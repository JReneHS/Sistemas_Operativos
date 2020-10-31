/*
=========================================================
	PROGRAMA #2:
		Paso de parámetros desde la linea de órdenes
	Archivo: c002.c
=========================================================
 */

#include <stdio.h>

int main(int argc, char const *argv[])
{
	int i;
	printf("Número de argumentos: %d\n",argc);
	printf("Nombre del Programa: %s\n",argv[0]);
	for (i = 0; i < 50; i++)
	{
		printf("Argumento %d = %s\n",i,argv[i]);
	}


	return 0;
}
/*
Número de argumentos: 1
Nombre del Programa: /home/gio/Documentos/SISTEMAS_OPERATIVOS/RECUPERACION/Procesos (Ruby)/c002
Argumento 0 = /home/gio/Documentos/SISTEMAS_OPERATIVOS/RECUPERACION/Procesos (Ruby)/c002
Argumento 1 = (null)
Argumento 2 = SHELL=/bin/bash
Argumento 3 = SESSION_MANAGER=local/gio-Satellite-M645:@/tmp/.ICE-unix/3904,unix/gio-Satellite-M645:/tmp/.ICE-unix/3904
Argumento 4 = QT_ACCESSIBILITY=1
Argumento 5 = COLORTERM=truecolor
Argumento 6 = XDG_CONFIG_DIRS=/etc/xdg/xdg-ubuntu:/etc/xdg
Argumento 7 = XDG_MENU_PREFIX=gnome-
Argumento 8 = TERM_PROGRAM_VERSION=1.48.2
Argumento 9 = GNOME_DESKTOP_SESSION_ID=this-is-deprecated
Argumento 10 = GTK_IM_MODULE=ibus
Argumento 11 = APPLICATION_INSIGHTS_NO_DIAGNOSTIC_CHANNEL=true
Argumento 12 = LANGUAGE=es_MX:es
Argumento 13 = QT4_IM_MODULE=ibus
Argumento 14 = JAVA_HOME=/usr/lib/jvm/java-14-openjdk-amd64
Argumento 15 = GNOME_SHELL_SESSION_MODE=ubuntu
Argumento 16 = SSH_AUTH_SOCK=/run/user/1000/keyring/ssh
Argumento 17 = XMODIFIERS=@im=ibus
Argumento 18 = DESKTOP_SESSION=ubuntu
Argumento 19 = SSH_AGENT_PID=3842
Argumento 20 = BAMF_DESKTOP_FILE_HINT=/var/lib/snapd/desktop/applications/code_code.desktop
Argumento 21 = GTK_MODULES=gail:atk-bridge
Argumento 22 = PWD=/home/gio/Documentos/SISTEMAS_OPERATIVOS/RECUPERACION/Procesos (Ruby)
Argumento 23 = GSETTINGS_SCHEMA_DIR=/snap/code/42/usr/share/glib-2.0/schemas
Argumento 24 = XDG_SESSION_DESKTOP=ubuntu
Argumento 25 = LOGNAME=gio
Argumento 26 = XDG_SESSION_TYPE=x11
Argumento 27 = GPG_AGENT_INFO=/run/user/1000/gnupg/S.gpg-agent:0:1
Argumento 28 = XAUTHORITY=/run/user/1000/gdm/Xauthority
Argumento 29 = VSCODE_GIT_ASKPASS_NODE=/snap/code/42/usr/share/code/code
Argumento 30 = GJS_DEBUG_TOPICS=JS ERROR;JS LOG
Argumento 31 = WINDOWPATH=2
Argumento 32 = HOME=/home/gio
Argumento 33 = USERNAME=gio
Argumento 34 = IM_CONFIG_PHASE=1
Argumento 35 = LANG=es_MX.UTF-8
Argumento 36 = LS_COLORS=rs=0:di=01;34:ln=01;36:mh=00:pi=40;33:so=01;35:do=01;35:bd=40;33;01:cd=40;33;01:or=40;31;01:mi=00:su=37;41:sg=30;43:ca=30;41:tw=30;42:ow=34;42:st=37;44:ex=01;32:*.tar=01;31:*.tgz=01;31:*.arc=01;31:*.arj=01;31:*.taz=01;31:*.lha=01;31:*.lz4=01;31:*.lzh=01;31:*.lzma=01;31:*.tlz=01;31:*.txz=01;31:*.tzo=01;31:*.t7z=01;31:*.zip=01;31:*.z=01;31:*.dz=01;31:*.gz=01;31:*.lrz=01;31:*.lz=01;31:*.lzo=01;31:*.xz=01;31:*.zst=01;31:*.tzst=01;31:*.bz2=01;31:*.bz=01;31:*.tbz=01;31:*.tbz2=01;31:*.tz=01;31:*.deb=01;31:*.rpm=01;31:*.jar=01;31:*.war=01;31:*.ear=01;31:*.sar=01;31:*.rar=01;31:*.alz=01;31:*.ace=01;31:*.zoo=01;31:*.cpio=01;31:*.7z=01;31:*.rz=01;31:*.cab=01;31:*.wim=01;31:*.swm=01;31:*.dwm=01;31:*.esd=01;31:*.jpg=01;35:*.jpeg=01;35:*.mjpg=01;35:*.mjpeg=01;35:*.gif=01;35:*.bmp=01;35:*.pbm=01;35:*.pgm=01;35:*.ppm=01;35:*.tga=01;35:*.xbm=01;35:*.xpm=01;35:*.tif=01;35:*.tiff=01;35:*.png=01;35:*.svg=01;35:*.svgz=01;35:*.mng=01;35:*.pcx=01;35:*.mov=01;35:*.mpg=01;35:*.mpeg=01;35:*.m2v=01;35:*.mkv=01;35:*.webm=01;35:*.ogm=01;35:*.mp4=01;35:*.m4v=01;35:*.mp4v=01;35:*.vob=01;35:*.qt=01;35:*.nuv=01;35:*.wmv=01;35:*.asf=01;35:*.rm=01;35:*.rmvb=01;35:*.flc=01;35:*.avi=01;35:*.fli=01;35:*.flv=01;35:*.gl=01;35:*.dl=01;35:*.xcf=01;35:*.xwd=01;35:*.yuv=01;35:*.cgm=01;35:*.emf=01;35:*.ogv=01;35:*.ogx=01;35:*.aac=00;36:*.au=00;36:*.flac=00;36:*.m4a=00;36:*.mid=00;36:*.midi=00;36:*.mka=00;36:*.mp3=00;36:*.mpc=00;36:*.ogg=00;36:*.ra=00;36:*.wav=00;36:*.oga=00;36:*.opus=00;36:*.spx=00;36:*.xspf=00;36:
Argumento 37 = XDG_CURRENT_DESKTOP=Unity
Argumento 38 = DISABLE_WAYLAND=1
Argumento 39 = GIT_ASKPASS=/snap/code/42/usr/share/code/resources/app/extensions/git/dist/askpass.sh
Argumento 40 = INVOCATION_ID=ba5fa65da22c4f04903c8121a1ad7198
Argumento 41 = MANAGERPID=2784
Argumento 42 = CHROME_DESKTOP=code-url-handler.desktop
Argumento 43 = CLUTTER_IM_MODULE=ibus
Argumento 44 = GJS_DEBUG_OUTPUT=stderr
Argumento 45 = LESSCLOSE=/usr/bin/lesspipe %s %s
Argumento 46 = XDG_SESSION_CLASS=user
Argumento 47 = TERM=xterm-256color
Argumento 48 = LESSOPEN=| /usr/bin/lesspipe %s
Argumento 49 = USER=gio
*/