# auto-push.ps1
#
# Watches a local git repo for changes and, if any are found,
# stages, commits, and pushes them automatically.
#
# This runs ON YOUR WINDOWS MACHINE via Task Scheduler.
# It only works while Windows is actually on/awake at the scheduled time.

# ---- CONFIG: edit this to point at your repo ----
# NOTE: replace this with the EXACT path to your "C programming" folder.
# Run `Get-Location` from inside that folder (in PowerShell) to get the
# correct value, then paste it here exactly.
$RepoDir  = "E:\About me\c programing"
$Branch   = "master"
$LogFile  = "$env:USERPROFILE\auto-push.log"
# --------------------------------------------------

function Write-Log {
    param([string]$Message)
    $timestamp = Get-Date -Format "yyyy-MM-dd HH:mm:ss"
    Add-Content -Path $LogFile -Value "$timestamp - $Message"
}

if (-not (Test-Path $RepoDir)) {
    Write-Log "ERROR: repo dir not found: $RepoDir"
    exit 1
}

Set-Location $RepoDir

# Confirm this is actually a git repo
git rev-parse --is-inside-work-tree *> $null
if ($LASTEXITCODE -ne 0) {
    Write-Log "ERROR: $RepoDir is not a git repo"
    exit 1
}

# Stage everything: new, modified, deleted files
git add -A

# Check if anything is actually staged
git diff --cached --quiet
if ($LASTEXITCODE -eq 0) {
    Write-Log "no changes, skipping"
    exit 0
}

$changedFiles = (git diff --cached --name-only) -join ", "
$commitMsg = "auto: update $(Get-Date -Format 'yyyy-MM-dd HH:mm') - $changedFiles"

git commit -m "$commitMsg" *>> $LogFile

git push origin $Branch *>> $LogFile
if ($LASTEXITCODE -eq 0) {
    Write-Log "pushed successfully: $changedFiles"
} else {
    Write-Log "ERROR: push failed"
    exit 1
}
