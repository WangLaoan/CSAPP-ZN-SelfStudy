# CSAPP-ZN-SelfStudy
CSAPP实验汉化，包括配置/实际完成时踩过的坑；）

# 实验环境配置
整个实验环境是UNIX系统环境，考虑国内大部分是Win, 推荐Win10安装WSL(搜索关键字：wsl安装), linux版本推荐Ubuntu
p.s. linux 高手可跳过
## WSL配置
主要目的：安装编译环境(gcc、make),鉴于连接国外太慢，推荐先apt改源

以下命令都是在安装好WSL-Ubuntu之后，在Linux Shell中进行的（粘贴没法用Ctrl+v, 但是在Shell里直接鼠标右键单击，就可以粘贴）
### apt改源（可选，建议）
```
#1. 备份
sudo cp /etc/apt/sources.list /etc/apt/sources.list.bak

#2. 编辑源列表文件
sudo vim /etc/apt/sources.list

#3 查看新版本信息
lsb_release -c  #获取Ubuntu版本昵称，我这里是focal

#4 替换
focal # 根据上面的版本名字修改下面涉及到的命令...一定改对！一定改对！一定改对！否则下面安装gcc编译环境包会出现依赖问题

deb http://mirrors.aliyun.com/ubuntu/ focal main restricted universe multiverse
deb-src http://mirrors.aliyun.com/ubuntu/ focal main restricted universe multiverse
deb http://mirrors.aliyun.com/ubuntu/ focal-security main restricted universe multiverse
deb-src http://mirrors.aliyun.com/ubuntu/ focal-security main restricted universe multiverse
deb http://mirrors.aliyun.com/ubuntu/ focal-updates main restricted universe multiverse
deb-src http://mirrors.aliyun.com/ubuntu/ focal-updates main restricted universe multiverse
deb http://mirrors.aliyun.com/ubuntu/ focal-backports main restricted universe multiverse
deb-src http://mirrors.aliyun.com/ubuntu/ focal-backports main restricted universe multiverse
deb http://mirrors.aliyun.com/ubuntu/ focal-proposed main restricted universe multiverse
deb-src http://mirrors.aliyun.com/ubuntu/ focal-proposed main restricted universe multiverse

#5 更新软件列表
sudo apt-get update

#6. 更新软件包
sudo apt-get upgrade
```

### 安装 编译/构建环境
```
sudo apt install build-essential
```

### vim编辑器配置(可选)
sudo vim /etc/vim/vimrc
```
syn on                      "语法支持
colorscheme murphy
set go=

"common conf {{             通用配置
"set ai                      "自动缩进
set bs=2                    "在insert模式下用退格键删除
set showmatch               "代码匹配
"set laststatus=2            "总是显示状态行
set expandtab               "以下三个配置配合使用，设置tab和缩进空格数
set shiftwidth=4
set tabstop=4
"set cursorline              "为光标所在行加下划线
set number                  "显示行号
set autoread                "文件在Vim之外修改过，自动重新读入
set mousemodel=popup

set ignorecase              "检索时忽略大小写
"set fileencodings=uft-8,gbk "使用utf-8或gbk打开文件
set hls                     "检索时高亮显示匹配项
set helplang=cn             "帮助系统设置为中文
"set foldmethod=syntax       "代码折叠
"}}



"使鼠标可点击复制
set mouse=a
"设置字体
set guifont=文泉驿等宽微米黑\ 9
set lines=38 columns=116                          
```

### Shell美化(可选)
[windows控制台主题美化工具-colortool](https://www.cnblogs.com/DHclly/p/10822804.html)

