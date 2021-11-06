#pragma once
/* Exclude.h — Определения переменных для исключения ненужных заголовочных файлов. За дополнительными разъяснениями обратитесь в [30]. */

#define WIN32_LEAN_AND_MEAN

/* Весьма эффективная мера, уменьшающая размер предварительно скомпилированного заголовочного файла (pch) почти в два раза. */

/* Эти определения также уменьшают размер pch-файла и уменьшают время компиляции. Все программы в данной книге будут компилироваться с этими определениями. От использования средств защиты можно отказаться при помощи оператора #define NOSECURITY. */

#define NOATOM 

#define NOCLIPBOARD 

#define NOCOMM 

#define NOCTLMGR 

#define NOCOLOR 

#define NODEFERWINDOWPOS 

#define NODESKTOP 

#define NODRAWTEXT 

#define NOEXTAPI 

#define NOGDICAPMASKS 

#define NOHELP 

#define NOICONS 

#define NOTIME 

#define NOIMM 

#define NOKANJI 

#define NOKERNEL 

#define NOKEYSTATES 

#define NOMCX 

#define NOMEMMGR 

#define NOMENUS 

#define NOMETAFILE 

#define NOMSG 

#define NONCMESSAGES 

#define NOPROFILER 

#define NORASTEROPS 

#define NORESOURCE 

#define NOSCROLL 

#define NOSERVICE 

#define NOSHOWWINDOW 

#define NOSOUND 

#define NOSYSCOMMANDS 

#define NOSYSMETRICS 

#define NOSYSPARAMS 

#define NOTEXTMETRIC 

#define NOVIRTUALKEYCODES 

#define NOWH 

#define NOWINDOWSTATION 

#define NOWINMESSAGES 

#define NOWINOFFSETS 

#define NOWIMSTYLES 

#define OEMRESOURCE
