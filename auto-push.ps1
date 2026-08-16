# auto-push.ps1
#
# Automatically commits and pushes a Git repository.
# A commit is created every time the script runs,
# even if there are no file changes.

# ---- CONFIG ----
$RepoDir  = "E:\About me\c programing"
$Branch   = "master"
$LogFile  = "$env:USERPROFILE\auto-push.log"
# ----------------



function Write-Log {
    param([string]$Message)

    $timestamp = Get-Date -Format "yyyy-MM-dd HH:mm:ss"
    Add-Content -Path $LogFile -Value "$timestamp - $Message"
}

# Check repository directory
if (-not (Test-Path $RepoDir)) {
    Write-Log "ERROR: repo dir not found: $RepoDir"
    exit 1
}

Set-Location $RepoDir

# Check if this is a Git repository
git rev-parse --is-inside-work-tree *> $null

if ($LASTEXITCODE -ne 0) {
    Write-Log "ERROR: $RepoDir is not a git repo"
    exit 1
}

# Stage all changes
git add -A

# Check whether there are actual changes
git diff --cached --quiet

if ($LASTEXITCODE -eq 0) {
    # No changes - create an empty commit
    $commitMsg = "auto: daily update $(Get-Date -Format 'yyyy-MM-dd HH:mm')"

    git commit --allow-empty -m "$commitMsg" *>> $LogFile

    if ($LASTEXITCODE -eq 0) {
        Write-Log "no file changes - empty commit created"
    }
    else {
        Write-Log "ERROR: empty commit failed"
        exit 1
    }
}
else {
    # Changes exist
    $changedFiles = (git diff --cached --name-only) -join ", "
    $commitMsg = "auto: update $(Get-Date -Format 'yyyy-MM-dd HH:mm') - $changedFiles"

    git commit -m "$commitMsg" *>> $LogFile

    if ($LASTEXITCODE -ne 0) {
        Write-Log "ERROR: commit failed"
        exit 1
    }

    Write-Log "changes committed: $changedFiles"
}

# Push to GitHub
git push origin $Branch *>> $LogFile

if ($LASTEXITCODE -eq 0) {
    Write-Log "pushed successfully"
}
else {
    Write-Log "ERROR: push failed"
    exit 1
}
