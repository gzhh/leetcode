#! /bin/bash

# Source : https://leetcode.com/problems/tenth-line/description/
# Author : Zhonghuan Gao
# Date   : 2018-07-31

# ************************************************

# Given a text file file.txt, print just the 10th line of the file.

# ************************************************

#显示文件的第十行内容
echo `sed -n '10p' file.txt`

