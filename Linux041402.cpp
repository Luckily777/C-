1 if v:lang = ~"utf8$" || v : lang = ~"UTF-8$"
2    set fileencodings = ucs - bom, utf - 8, latin1
3 endif
4
5 set nocompatible        " Use Vim defaults (much better!)
6 set bs = indent, eol, start         " allow backspacing over everything in insert mode
7 "set ai                 " always set autoindenting on
8 "set backup             " keep a backup file
9 set viminfo = '20,\"50    " read/write a .viminfo file, don't store more
10                         " than 50 lines of registers
11 set history = 50          " keep 50 lines of command line history
12 set ruler               " show the cursor position all the time
13
14 " Only do this part when compiled with support for autocommands
15 if has("autocmd")
16   augroup redhat
17   autocmd!
18   " In text files, always limit the width of text to 78 characters
19   " autocmd BufRead *.txt set tw=78
20   " When editing a file, always jump to the last cursor position
21   autocmd BufReadPost *
22   \ if line("'\"") > 0 && line("'\"") <= line("$") |
23   \   exe "normal! g'\"" |
24   \ endif
25   " don't write swapfile on most commonly used directories for NFS mounts or USB sticks
26   autocmd BufNewFile, BufReadPre / media/*,/run/media/*,/mnt/* set directory=~/tmp,/var/tmp,/tmp
27   " start with spec file template
28   autocmd BufNewFile *.spec 0r /usr/share/vim/vimfiles/template.spec
29   augroup END
30 endif
31
32 if has("cscope") && filereadable("/usr/bin/cscope")
33    set csprg=/usr/bin/cscope
34    set csto=0
35    set cst
36    set nocsverb
37    " add any database in current directory
38    if filereadable("cscope.out")
39       cs add $PWD/cscope.out
40    " else add database pointed to by environment
41    elseif $CSCOPE_DB != ""
42       cs add $CSCOPE_DB
43    endif
44    set csverb
45 endif
46
47 " Switch syntax highlighting on, when the terminal has colors
 48 " Also switch on highlighting the last used search pattern.
 49 if &t_Co > 2 || has("gui_running")
 50   syntax on
 51   set hlsearch
 52 endif
 53
 54 filetype plugin on
 55
 56 if &term=="xterm"
 57      set t_Co=8
 58      set t_Sb=^[[4%dm
 59      set t_Sf=^[[3%dm
 60 endif
 61
 62 " Don't wake up system with blinking cursor:
 63 " http://www.linuxpowertop.org/known.php
 64 let &guicursor = &guicursor . ",a:blinkon0"
 65 set nu
