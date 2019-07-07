"语法高亮
     set nu!

     colorscheme desert 
     syntax enable 
     syntax on

" 解决插入模式下delete/backspce键失效问题
"set backspace=New 21 Game

" 插入匹配括号


"inoremap {<CR> {<CR>}<ESC>O
"inoremap { {}<LEFT>
inoremap { {<CR>}<ESC>O

inoremap ( ()<LEFT>
inoremap [ []<LEFT>
inoremap ' ''<LEFT>
inoremap " ""<LEFT>

" 输入一个字符时，如果上一个是{添加回车
function! RemoveNextDoubleCharmyfunc(char, charchar)
	let l:line = getline(".")
	let l:next_char = l:line[col(".")] "取得当前光标后一个字符

	let l:charenter = char('<CR>')
	
	if a:char == l:next_char
		execute "normal! a" . <CR><ESC>O . ""
	else
		execute "normal! O"
	end
endfunction
"inoremap <CR> <ESC>:call RemoveNextDoubleCharmyfunc('}')

" 输入一个字符时，如果下一个字符也是括号，则删除它，避免出现重复字符
function! RemoveNextDoubleChar(char)
	let l:line = getline(".")
	let l:next_char = l:line[col(".")] " 取得当前光标后一个字符

	if a:char == l:next_char
		execute "normal! l"
	else
		execute "normal! a" . a:char . ""
	end
endfunction
"execute "normal! a a:char"
inoremap ) <ESC>:call RemoveNextDoubleChar(')')<CR>a
inoremap ] <ESC>:call RemoveNextDoubleChar(']')<CR>a
inoremap } <ESC>:call RemoveNextDoubleChar('}')<CR>a


"<CR>a<enter><enter><up><tab>



" 设置winmanager
" 设置界面分割
let g:winManagerWindowLayout = "TagList|FileExplorer"
"设置winmanager的宽度，默认为25
let g:winManagerWidth = 20
let g:AutoOpenWinManager = 0
"定义打开关闭winmanager快捷键为F8
nmap <F8> :WMToggle<cr>

:set mousehide

"设置打开默认大小
set lines=155 columns=120
"打开初始位置	
winpos 1900 270
"au GUIEnter * simalt ~x

set guifont=courier_new:h10	"字体大小
 
"------------------------------------------------------------------------------  
"  < 判断操作系统是否是 Windows 还是 Linux >  
"------------------------------------------------------------------------------  
if(has("win32") || has("win64") || has("win95") || has("win16"))  
    let g:iswindows = 1  
else  
    let g:iswindows = 0  
endif  
   
"------------------------------------------------------------------------------  
"  < 判断是终端还是 Gvim >  
"------------------------------------------------------------------------------  
if has("gui_running")  
    let g:isGUI = 1  
else  
    let g:isGUI = 0  
endif  
   
"------------------------------------------------------------------------------  
"  < 编译、连接、运行配置 >  
"------------------------------------------------------------------------------  
" F9 一键保存、编译、连接存并运行  
map <F9> :call Run()<CR>  
imap <F9> <ESC>:call Run()<CR>  
   
" Ctrl + F9 一键保存并编译  
map <F10> :call Compile()<CR>  
imap <F10>: <ESC> call Compile()<CR>  
   
" Ctrl + F10 一键保存并连接  
map <c-F10> :call Link()<CR>  
imap <c-F10> <ESC>:call Link()<CR>  
   
let s:LastShellReturn_C = 0  
let s:LastShellReturn_L = 0  
let s:ShowWarning = 1  
let s:Obj_Extension = '.o'  
let s:Exe_Extension = '.exe'  
let s:Sou_Error = 0  
   
let s:windows_CFlags = 'gcc\ -fexec-charset=gbk\ -Wall\ -g\ -O0\ -c\ %\ -o\ %<.o'  
let s:linux_CFlags = 'gcc\ -Wall\ -g\ -O0\ -c\ %\ -o\ %<.o'  
   
let s:windows_CPPFlags = 'g++\ -fexec-charset=gbk\ -Wall\ -g\ -O0\ -c\ %\ -o\ %<.o'  
let s:linux_CPPFlags = 'g++\ -Wall\ -g\ -O0\ -c\ %\ -o\ %<.o'  
   
func! Compile()  
    exe ":ccl"  
    exe ":update"  
    if expand("%:e") == "c" || expand("%:e") == "cpp" || expand("%:e") == "cxx"  
        let s:Sou_Error = 0  
        let s:LastShellReturn_C = 0  
        let Sou = expand("%:p")  
        let Obj = expand("%:p:r").s:Obj_Extension  
        let Obj_Name = expand("%:p:t:r").s:Obj_Extension  
        let v:statusmsg = ''  
        if !filereadable(Obj) || (filereadable(Obj) && (getftime(Obj) < getftime(Sou)))  
            redraw!  
            if expand("%:e") == "c"  
                if g:iswindows  
                    exe ":setlocal makeprg=".s:windows_CFlags  
                else  
                    exe ":setlocal makeprg=".s:linux_CFlags  
                endif  
                echohl WarningMsg | echo " compiling..."  
                silent make  
            elseif expand("%:e") == "cpp" || expand("%:e") == "cxx"  
                if g:iswindows  
                    exe ":setlocal makeprg=".s:windows_CPPFlags  
                else  
                    exe ":setlocal makeprg=".s:linux_CPPFlags  
                endif  
                echohl WarningMsg | echo " compiling..."  
                silent make  
            endif  
            redraw!  
            if v:shell_error != 0  
                let s:LastShellReturn_C = v:shell_error  
            endif  
            if g:iswindows  
                if s:LastShellReturn_C != 0  
                    exe ":bo cope"  
                    echohl WarningMsg | echo " compilation failed"  
                else  
                    if s:ShowWarning  
                        exe ":bo cw"  
                    endif  
                    echohl WarningMsg | echo " compilation successful"  
                endif  
            else  
                if empty(v:statusmsg)  
                    echohl WarningMsg | echo " compilation successful"  
                else  
                    exe ":bo cope"  
                endif  
            endif  
        else  
            echohl WarningMsg | echo ""Obj_Name"is up to date" 
            echohl WarningMsg | echo ""Obj_Name"is up to date"  
        endif  
    else  
        let s:Sou_Error = 1  
        echohl WarningMsg | echo " please choose the correct source file"  
    endif  
    exe ":setlocal makeprg=make"  
endfunc  
   
func! Link()  
    call Compile()  
    if s:Sou_Error || s:LastShellReturn_C != 0  
        return  
    endif  
    let s:LastShellReturn_L = 0  
    let Sou = expand("%:p")  
    let Obj = expand("%:p:r").s:Obj_Extension  
    if g:iswindows  
        let Exe = expand("%:p:r").s:Exe_Extension  
        let Exe_Name = expand("%:p:t:r").s:Exe_Extension  
    else  
        let Exe = expand("%:p:r")  
        let Exe_Name = expand("%:p:t:r")  
    endif  
    let v:statusmsg = ''  
    if filereadable(Obj) && (getftime(Obj) >= getftime(Sou))  
        redraw!  
        if !executable(Exe) || (executable(Exe) && getftime(Exe) < getftime(Obj))  
            if expand("%:e") == "c"  
                setlocal makeprg=gcc\ -o\ %<\ %<.o  
                echohl WarningMsg | echo " linking..."  
                silent make  
            elseif expand("%:e") == "cpp" || expand("%:e") == "cxx"  
                setlocal makeprg=g++\ -o\ %<\ %<.o  
                echohl WarningMsg | echo " linking..."  
                silent make  
            endif  
            redraw!  
            if v:shell_error != 0  
                let s:LastShellReturn_L = v:shell_error  
            endif  
            if g:iswindows  
                if s:LastShellReturn_L != 0  
                    exe ":bo cope"  
                    echohl WarningMsg | echo " linking failed"  
                else  
                    if s:ShowWarning  
                        exe ":bo cw"  
                    endif  
                    echohl WarningMsg | echo " linking successful"  
                endif  
            else  
                if empty(v:statusmsg)  
                    echohl WarningMsg | echo " linking successful"  
                else  
                    exe ":bo cope"  
                endif  
            endif  
        else  
            echohl WarningMsg | echo ""Exe_Name"is up to date"  
        endif  
    endif  
    setlocal makeprg=make  
endfunc  
   
func! Run()  
    let s:ShowWarning = 0  
    call Link()  
    let s:ShowWarning = 1  
    if s:Sou_Error || s:LastShellReturn_C != 0 || s:LastShellReturn_L != 0  
        return  
    endif  
    let Sou = expand("%:p")  
    let Obj = expand("%:p:r").s:Obj_Extension  
    if g:iswindows  
        let Exe = expand("%:p:r").s:Exe_Extension  
    else  
        let Exe = expand("%:p:r")  
    endif  
    if executable(Exe) && getftime(Exe) >= getftime(Obj) && getftime(Obj) >= getftime(Sou)  
        redraw!  
        echohl WarningMsg | echo " running..."  
        if g:iswindows  
            exe ":!%<.exe"  
        else  
            if g:isGUI  
                exe ":!gnome-terminal -e ./%<"  
            else  
                exe ":!./%<"  
            endif  
        endif  
        redraw!  
        echohl WarningMsg | echo " running finish"  
    endif  
endfunc  

let g:winManagerWindowLayout='FileExplorer|TagList'
nmap wm :WMToggle<cr>

" ctags 索引文件 (根据已经生成的索引文件添加即可, 这里我额外添加了 hge 和 curl 的索引文件)
set tags+=C:/file/ctags58/cpp
set tags+=D:/ctags/tags/hge
set tags+=D:/ctags/tags/curl
" OmniCppComplete
let OmniCpp_NamespaceSearch = 1
let OmniCpp_GlobalScopeSearch = 1
let OmniCpp_ShowAccess = 1
let OmniCpp_ShowPrototypeInAbbr = 1 " 显示函数参数列表
let OmniCpp_MayCompleteDot = 1   " 输入 .  后自动补全
let OmniCpp_MayCompleteArrow = 1 " 输入 -> 后自动补全
let OmniCpp_MayCompleteScope = 1 " 输入 :: 后自动补全
let OmniCpp_DefaultNamespaces = ["std", "_GLIBCXX_STD"]
" 自动关闭补全窗口
au CursorMovedI,InsertLeave * if pumvisible() == 0|silent! pclose|endif
set completeopt=menuone,menu,longest

"python设置

" 设置编码自动识别, 中文引号显示 
"set fileencodings=utf-8,cp936,big5,euc-jp,euc-kr,latin1,ucs-bom 
set fileencodings=utf-8,gbk 
set ambiwidth=double

"ColorScheme
colorscheme desert

" 允许退格键删除和tab操作 
set smartindent 
set smarttab 
set expandtab 
set tabstop=4 
set softtabstop=4 
set shiftwidth=4 
set backspace=2
set textwidth=10000

" 启用鼠标 
set mouse=a 

" 启用行号 
set nu

"自动补全 
filetype plugin indent on
set completeopt=longest,menu
"自动补全命令时候使用菜单式匹配列表 
set wildmenu
autocmd FileType ruby,eruby set omnifunc=rubycomplete#Complete
autocmd FileType python set omnifunc=pythoncomplete#Complete
autocmd FileType javascript set omnifunc=javascriptcomplete#CompleteJS
autocmd FileType html set omnifunc=htmlcomplete#CompleteTags
autocmd FileType css set omnifunc=csscomplete#CompleteCSS
autocmd FileType xml set omnifunc=xmlcomplete#CompleteTags
autocmd FileType java set omnifunc=javacomplete#Complet

"Pydiction
let g:pydiction_location = 'C:\file\vim\vim80\ftplugin\complete-dict'
let Tlist_Ctags_Cmd='ctags.exe'

"map <F5> :!python.exe % <enter>
"imap <F5> :w:!python.exe % <enter>

map <F5> :call RunPython()<CR>
imap <F5> <ESC>:call RunPython()<CR>
func! RunPython()
    if &filetype == 'python'
		exec ":w"
        exec "!python %"
    endif
endfunc


"单个文件编译
"map <F10> :call Do_OneFileMake()<CR>
"imap <F10> :call Do_OneFileMake()<CR>
function Do_OneFileMake()
    if expand("%:p:h")!=getcwd()
        echohl WarningMsg | echo "Fail to make! This file is not in the current dir! Press <F7> to redirect to the dir of this file." | echohl None
        return
    endif
    let sourcefileename=expand("%:t")
    if (sourcefileename=="" || (&filetype!="cpp" && &filetype!="c"))
        echohl WarningMsg | echo "Fail to make! Please select the right file!" | echohl None
        return
    endif
    let deletedspacefilename=substitute(sourcefileename,' ','','g')
    if strlen(deletedspacefilename)!=strlen(sourcefileename)
        echohl WarningMsg | echo "Fail to make! Please delete the spaces in the filename!" | echohl None
        return
    endif
    if &filetype=="c"
        if g:iswindows==1
            set makeprg=gcc\ -o\ %<.exe\ %
        else
            set makeprg=gcc\ -o\ %<\ %
        endif
    elseif &filetype=="cpp"
        if g:iswindows==1
            set makeprg=g++\ -o\ %<.exe\ %
        else
            set makeprg=g++\ -o\ %<\ %
        endif
        "elseif &filetype=="cs"
        "set makeprg=csc\ \/nologo\ \/out:%<.exe\ %
    endif
    if(g:iswindows==1)
        let outfilename=substitute(sourcefileename,'\(\.[^.]*\)' ,'.exe','g')
        let toexename=outfilename
    else
        let outfilename=substitute(sourcefileename,'\(\.[^.]*\)' ,'','g')
        let toexename=outfilename
    endif
    if filereadable(outfilename)
        if(g:iswindows==1)
            let outdeletedsuccess=delete(getcwd()."\\".outfilename)
        else
            let outdeletedsuccess=delete("./".outfilename)
        endif
        if(outdeletedsuccess!=0)
            set makeprg=make
            echohl WarningMsg | echo "Fail to make! I cannot delete the ".outfilename | echohl None
            return
        endif
    endif
    execute "silent make"
    set makeprg=make
    execute "normal :"
    if filereadable(outfilename)
        if(g:iswindows==1)
            execute "!".toexename
        else
            execute "!./".toexename
        endif
    endif
    execute "copen"
endfunction
"进行make的设置
map <F11> :call Do_make()<CR>
map <c-F11> :silent make clean<CR>
function Do_make()
    set makeprg=make
    execute "silent make"
    execute "copen"
endfunction