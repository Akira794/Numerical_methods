#Makefile

#プロジェクト名とオブジェクトファイル名
program = output
objs = \
	dichotomy.o \


#定義済マクロの再定義
CC = gcc
CXX = g++
CFLAGS = -g -Wall

# サフィックスルール適用対象の拡張子の定義
.SUFFIXES: .c .o

#プライマリターゲット
$(program): $(objs)
	$(CXX) -o $@ $(objs)

#サフィックスルール
.c.o:
	$(CXX) $(CFLAGS) -c $<

#ヘッダファイルの依存関係
#func.o: func.h #(ex.)

#ファイル削除用ターゲット*.o 
.PHONY: clean
clean:
	$(RM) $(program) $(objs)


