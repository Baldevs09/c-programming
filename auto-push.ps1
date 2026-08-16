# auto-push.ps1
#
# Automatically commits and pushes a Git repository.
# Creates a commit every time the script runs:
# - Normal commit when files changed
# - Empty commit when there are no changes

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

# Get staged files
$changedFiles = @(git diff --cached --name-only)

if ($changedFiles.Count -gt 0) {

    # -------------------------
    # CHANGES EXIST
    # -------------------------

    $fileList = $changedFiles -join ", "
    $commitMsg = "auto: update $(Get-Date -Format 'yyyy-MM-dd HH:mm') - $fileList"

    git commit -m "$commitMsg" *>> $LogFile

    if ($LASTEXITCODE -ne 0) {
        Write-Log "ERROR: commit failed"
        exit 1
    }

    Write-Log "changes committed: $fileList"

}
else {

    # -------------------------
    # NO CHANGES
    # -------------------------

    $commitMsg = "auto: daily update $(Get-Date -Format 'yyyy-MM-dd HH:mm')"

    git commit --allow-empty -m "$commitMsg" *>> $LogFile

    if ($LASTEXITCODE -ne 0) {
        Write-Log "ERROR: empty commit failed"
        exit 1
    }

    Write-Log "no file changes - empty commit created"
}

# -------------------------
# PUSH TO GITHUB
# -------------------------

git push origin $Branch *>> $LogFile

if ($LASTEXITCODE -eq 0) {
    Write-Log "pushed successfully"
}
else {
    Write-Log "ERROR: push failed"
    exit 1
}
