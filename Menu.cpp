#include <iostream>
#include "Menu.h"
bool gameLoop = true;
std::string Menuu[6] = { R"(
MP""""""`MM M""""""""M MMP"""""""MM M""""""""M MP""""""`MM
M  mmmmm..M Mmmm  mmmM M' .mmmm  MM Mmmm  mmmM M  mmmmm..M
M.      `YM MMMM  MMMM M         `M MMMM  MMMM M.      `YM
MMMMMMM.  M MMMM  MMMM M  MMMMM  MM MMMM  MMMM MMMMMMM.  M
M. .MMM'  M MMMM  MMMM M  MMMMM  MM MMMM  MMMM M. .MMM'  M
Mb.     .dM MMMM  MMMM M  MMMMM  MM MMMM  MMMM Mb.     .dM
MMMMMMMMMMM MMMMMMMMMM MMMMMMMMMMMM MMMMMMMMMM MMMMMMMMMMM)",
R"(
M""MMMMM""M MM"""""""`YM M""""""'YMM MMP"""""""MM M""""""""M MM""""""""`M    M""MMMMMMMM MMP"""""YMM MM'"""""`MM
M  MMMMM  M MM  mmmmm  M M  mmmm. `M M' .mmmm  MM Mmmm  mmmM MM  mmmmmmmM    M  MMMMMMMM M' .mmm. `M M' .mmm. `M
M  MMMMM  M M'        .M M  MMMMM  M M         `M MMMM  MMMM M`      MMMM    M  MMMMMMMM M  MMMMM  M M  MMMMMMMM
M  MMMMM  M MM  MMMMMMMM M  MMMMM  M M  MMMMM  MM MMMM  MMMM MM  MMMMMMMM    M  MMMMMMMM M  MMMMM  M M  MMM   `M
M  `MMM'  M MM  MMMMMMMM M  MMMM' .M M  MMMMM  MM MMMM  MMMM MM  MMMMMMMM    M  MMMMMMMM M. `MMM' .M M. `MMM' .M
Mb       dM MM  MMMMMMMM M       .MM M  MMMMM  MM MMMM  MMMM MM        .M    M         M MMb     dMM MM.     .MM
MMMMMMMMMMM MMMMMMMMMMMM MMMMMMMMMMM MMMMMMMMMMMM MMMMMMMMMM MMMMMMMMMMMM    MMMMMMMMMMM MMMMMMMMMMM MMMMMMMMMMM)",
R"(
M""MMM""MMM""M MM""""""""`M MMP"""""""MM MM"""""""`YM MMP"""""YMM M"""""""`YM    M""MMMMMMMM MMP"""""YMM MM'"""""`MM
M  MMM  MMM  M MM  mmmmmmmM M' .mmmm  MM MM  mmmmm  M M' .mmm. `M M  mmmm.  M    M  MMMMMMMM M' .mmm. `M M' .mmm. `M
M  MMP  MMP  M M`      MMMM M         `M M'        .M M  MMMMM  M M  MMMMM  M    M  MMMMMMMM M  MMMMM  M M  MMMMMMMM
M  MM'  MM' .M MM  MMMMMMMM M  MMMMM  MM MM  MMMMMMMM M  MMMMM  M M  MMMMM  M    M  MMMMMMMM M  MMMMM  M M  MMM   `M
M  `' . '' .MM MM  MMMMMMMM M  MMMMM  MM MM  MMMMMMMM M. `MMM' .M M  MMMMM  M    M  MMMMMMMM M. `MMM' .M M. `MMM' .M
M    .d  .dMMM MM        .M M  MMMMM  MM MM  MMMMMMMM MMb     dMM M  MMMMM  M    M         M MMb     dMM MM.     .MM
MMMMMMMMMMMMMM MMMMMMMMMMMM MMMMMMMMMMMM MMMMMMMMMMMM MMMMMMMMMMM MMMMMMMMMMM    MMMMMMMMMMM MMMMMMMMMMM MMMMMMMMMMM)"				,
R"(
MM'""""'YMM MM"""""""`MM MM""""""""`M M""""""'YMM M""M M""""""""M MP""""""`MM
M' .mmm. `M MM  mmmm,  M MM  mmmmmmmM M  mmmm. `M M  M Mmmm  mmmM M  mmmmm..M
M  MMMMMooM M'        .M M`      MMMM M  MMMMM  M M  M MMMM  MMMM M.      `YM
M  MMMMMMMM MM  MMMb. "M MM  MMMMMMMM M  MMMMM  M M  M MMMM  MMMM MMMMMMM.  M
M. `MMM' .M MM  MMMMM  M MM  MMMMMMMM M  MMMM' .M M  M MMMM  MMMM M. .MMM'  M
MM.     .dM MM  MMMMM  M MM        .M M       .MM M  M MMMM  MMMM Mb.     .dM
MMMMMMMMMMM MMMMMMMMMMMM MMMMMMMMMMMM MMMMMMMMMMM MMMM MMMMMMMMMM MMMMMMMMMMM)" ,
R"(
MMP"""""""MM MM'""""'YMM M""MMMMM""MM M""M MM""""""""`M M""MMMMM""M MM""""""""`M M"""""`'"""`YM MM""""""""`M M"""""""`YM M""""""""M MP""""""`MM
M' .mmmm  MM M' .mmm. `M M  MMMMM  MM M  M MM  mmmmmmmM M  MMMMM  M MM  mmmmmmmM M  mm.  mm.  M MM  mmmmmmmM M  mmmm.  M Mmmm  mmmM M  mmmmm..M
M         `M M  MMMMMooM M         `M M  M M`      MMMM M  MMMMP  M M`      MMMM M  MMM  MMM  M M`      MMMM M  MMMMM  M MMMM  MMMM M.      `YM
M  MMMMM  MM M  MMMMMMMM M  MMMMM  MM M  M MM  MMMMMMMM M  MMMM' .M MM  MMMMMMMM M  MMM  MMM  M MM  MMMMMMMM M  MMMMM  M MMMM  MMMM MMMMMMM.  M
M  MMMMM  MM M. `MMM' .M M  MMMMM  MM M  M MM  MMMMMMMM M  MMP' .MM MM  MMMMMMMM M  MMM  MMM  M MM  MMMMMMMM M  MMMMM  M MMMM  MMMM M. .MMM'  M
M  MMMMM  MM MM.     .dM M  MMMMM  MM M  M MM        .M M     .dMMM MM        .M M  MMM  MMM  M MM        .M M  MMMMM  M MMMM  MMMM Mb.     .dM
MMMMMMMMMMMM MMMMMMMMMMM MMMMMMMMMMMM MMMM MMMMMMMMMMMM MMMMMMMMMMM MMMMMMMMMMMM MMMMMMMMMMMMMM MMMMMMMMMMMM MMMMMMMMMMM MMMMMMMMMM MMMMMMMMMMM)",
R"(
M"""""`'"""`YM MMP"""""""MM M""M M"""""""`YM    M"""""`'"""`YM MM""""""""`M M"""""""`YM M""MMMMM""M
M  mm.  mm.  M M' .mmmm  MM M  M M  mmmm.  M    M  mm.  mm.  M MM  mmmmmmmM M  mmmm.  M M  MMMMM  M
M  MMM  MMM  M M         `M M  M M  MMMMM  M    M  MMM  MMM  M M`      MMMM M  MMMMM  M M  MMMMM  M
M  MMM  MMM  M M  MMMMM  MM M  M M  MMMMM  M    M  MMM  MMM  M MM  MMMMMMMM M  MMMMM  M M  MMMMM  M 
M  MMM  MMM  M M  MMMMM  MM M  M M  MMMMM  M    M  MMM  MMM  M MM  MMMMMMMM M  MMMMM  M M  `MMM'  M
M  MMM  MMM  M M  MMMMM  MM M  M M  MMMMM  M    M  MMM  MMM  M MM        .M M  MMMMM  M Mb       dM
MMMMMMMMMMMMMM MMMMMMMMMMMM MMMM MMMMMMMMMMM    MMMMMMMMMMMMMM MMMMMMMMMMMM MMMMMMMMMMM MMMMMMMMMMM)" };

std::string Menu[3] = { R"(
MP""""""`MM M""""""""M MMP"""""""MM MM"""""""`MM M""""""""M    MM'"""""`MM MMP"""""""MM M"""""`'"""`YM MM""""""""`M 
M  mmmmm..M Mmmm  mmmM M' .mmmm  MM MM  mmmm,  M Mmmm  mmmM    M' .mmm. `M M' .mmmm  MM M  mm.  mm.  M MM  mmmmmmmM 
M.      `YM MMMM  MMMM M         `M M'        .M MMMM  MMMM    M  MMMMMMMM M         `M M  MMM  MMM  M M`      MMMM 
MMMMMMM.  M MMMM  MMMM M  MMMMM  MM MM  MMMb. "M MMMM  MMMM    M  MMM   `M M  MMMMM  MM M  MMM  MMM  M MM  MMMMMMMM 
M. .MMM'  M MMMM  MMMM M  MMMMM  MM MM  MMMMM  M MMMM  MMMM    M. `MMM' .M M  MMMMM  MM M  MMM  MMM  M MM  MMMMMMMM 
Mb.     .dM MMMM  MMMM M  MMMMM  MM MM  MMMMM  M MMMM  MMMM    MM.     .MM M  MMMMM  MM M  MMM  MMM  M MM        .M 
MMMMMMMMMMM MMMMMMMMMM MMMMMMMMMMMM MMMMMMMMMMMM MMMMMMMMMM    MMMMMMMMMMM MMMMMMMMMMMM MMMMMMMMMMMMMM MMMMMMMMMMMM)",
R"(
MMP"""""YMM MM"""""""`YM M""""""""M M""M MMP"""""YMM M"""""""`YM MP""""""`MM 
M' .mmm. `M MM  mmmmm  M Mmmm  mmmM M  M M' .mmm. `M M  mmmm.  M M  mmmmm..M 
M  MMMMM  M M'        .M MMMM  MMMM M  M M  MMMMM  M M  MMMMM  M M.      `YM 
M  MMMMM  M MM  MMMMMMMM MMMM  MMMM M  M M  MMMMM  M M  MMMMM  M MMMMMMM.  M 
M. `MMM' .M MM  MMMMMMMM MMMM  MMMM M  M M. `MMM' .M M  MMMMM  M M. .MMM'  M 
MMb     dMM MM  MMMMMMMM MMMM  MMMM M  M MMb     dMM M  MMMMM  M Mb.     .dM 
MMMMMMMMMMM MMMMMMMMMMMM MMMMMMMMMM MMMM MMMMMMMMMMM MMMMMMMMMMM MMMMMMMMMMM )",
R"(
MM'"""""`MMM M""MMMMM""M M""M M""""""""M
M  .mmm,  MM M  MMMMM  M M  M Mmmm  mmmM
M  MMMMM  MM M  MMMMM  M M  M MMMM  MMMM
M  MM  M  MM M  MMMMM  M M  M MMMM  MMMM
M  `MM    MM M  `MMM'  M M  M MMMM  MMMM
MM.    .. `M Mb       dM M  M MMMM  MMMM
MMMMMMMMMMMM MMMMMMMMMMM MMMM MMMMMMMMMM)" };