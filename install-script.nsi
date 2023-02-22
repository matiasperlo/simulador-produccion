; script en empaquetador de mi programa con NSIS v3.08

;--------------------------------

; The name of the installer
Name "Simulador Wizard"

; The file to write
OutFile "sim-1.0-setup.exe"

; Request application privileges for Windows Vista
RequestExecutionLevel user

; Build Unicode installer
Unicode True

; The default installation directory
InstallDir $PROGRAMFILES\Simulador

;--------------------------------

; Paginas del wizard

; para la instalacion
Page directory
Page instfiles

; para la desinstalacion
UninstPage uninstConfirm
UninstPage instfiles

;--------------------------------
; The stuff to install
Section "" ; Seccion oculta para iniciar.
  
  ; Set output path to the installation directory.
  SetOutPath $INSTDIR
  
  ; Los archivos para la instalacion aca
  File "sc.exe"
  File "*.dll"

  SetOutPath $INSTDIR\iconengines
  File "iconengines\*.dll"
  
  SetOutPath $INSTDIR\imageformats
  File "imageformats\*.dll"

  SetOutPath $INSTDIR\images
  File "images\*.png"
  File "images\*.ico"

  SetOutPath $INSTDIR\platforms
  File "platforms\*.dll"

  SetOutPath $INSTDIR\styles
  File "styles\*.dll"

  SetOutPath $INSTDIR\translations
  File "translations\*.qm"
  
  ; Este registro sirve para que el programa aparezca en el listado de programas de Windows
  WriteRegStr   HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\Simulador" "DisplayName" "Simulador de Cultivos"
  WriteRegStr   HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\Simulador" "UninstallString" '"$INSTDIR\uninstall.exe"'
  WriteRegDWORD HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\Simulador" "NoModify" 1
  WriteRegDWORD HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\Simulador" "NoRepair" 1
  WriteUninstaller "$INSTDIR\uninstall.exe"

  ; crear los shortcuts para usar
  CreateDirectory "$SMPROGRAMS\Simulador"
  CreateShortcut  "$SMPROGRAMS\Simulador\Simulador de Cultivos.lnk" "$INSTDIR\sc.exe"
  CreateShortcut  "$DESKTOP\Simulador de Cultivos.lnk" "$INSTDIR\sc.exe"
SectionEnd

; Uninstaller

Section "Uninstall" ; eliminar todos los archivos y registros

  ; Remove registry keys
  DeleteRegKey HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\Simulador"

  ; Remove files and uninstaller
  Delete $INSTDIR\iconengines\*
  Delete $INSTDIR\imageformats\*
  Delete $INSTDIR\images\*
  Delete $INSTDIR\platforms\*
  Delete $INSTDIR\styles\*
  Delete $INSTDIR\translations\*
  Delete $INSTDIR\*

  ; Remove shortcuts, if any
  Delete "$SMPROGRAMS\Simulador\*.lnk"
  Delete "$DESKTOP\Simulador de Cultivos.lnk"


  ; Remove directories
  RMDir "$SMPROGRAMS\Simulador"
  RMDir "$INSTDIR"

SectionEnd