# Define the path to the source code directory
$sourceDirectory = Split-Path -Path $MyInvocation.MyCommand.Path
Write-Output $sourceDirectory

# Define the path to the build directory
$buildDirectory = "build"

# Create the build directory if it doesn't exist
if (!(Test-Path $buildDirectory)) {
    New-Item -ItemType Directory -Path $buildDirectory
}

# Change to the build directory
Set-Location $buildDirectory

# Call cmake with the source directory
cmake ${sourceDirectory}/CMakeLists.txt -Wno-dev
