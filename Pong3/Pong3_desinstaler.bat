@echo off
title Désinstallation de Pong3

:: Vérifie que l'utilisateur veut vraiment désinstaller
echo Etes-vous sur de vouloir desinstaller Pong3 ? (O/N)
set /p choix=
if /i "%choix%" neq "O" (
    echo Desinstallation annulee.
    pause
    exit /b
)

:: Chemin du dossier d'installation (le dossier où se trouve ce script)
set "install_dir=%~dp0"
echo Suppression des fichiers dans : %install_dir%

:: Supprime les fichiers principaux du jeu
del /f /q "%install_dir%Pong3.exe" 2>nul
del /f /q "%install_dir%Qt6Core.dll" 2>nul
del /f /q "%install_dir%Qt6Gui.dll" 2>nul
del /f /q "%install_dir%Qt6Widgets.dll" 2>nul
del /f /q "%install_dir%logo.ico" 2>nul
del /f /q "%install_dir%README.md" 2>nul

:: Supprime les dossiers spécifiques
if exist "%install_dir%qtc_clangd\" (
    rmdir /s /q "%install_dir%qtc_clangd"
    echo Dossier qtc_clangd supprime.
)
if exist "%install_dir%platforms\" (
    rmdir /s /q "%install_dir%platforms"
    echo Dossier platforms supprime.
)
if exist "%install_dir%Pong3_autogen\" (
    rmdir /s /q "%install_dir%Pong3_autogen"
    echo Dossier Pong3_autogen supprime.
)

:: Supprime le raccourci bureau s'il existe
if exist "%USERPROFILE%\Desktop\Pong3.lnk" (
    del /f /q "%USERPROFILE%\Desktop\Pong3.lnk"
    echo Raccourci bureau supprime.
)

:: Supprime le dossier d'installation s'il est vide
cd /d "%install_dir%"
cd ..
rmdir /s /q "%~nx0" 2>nul

echo Desinstallation terminee. Vous pouvez supprimer ce script.
pause
