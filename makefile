# TARGET NAME
TARGET := ex02


# OBJECT FILES
OBJS := ex02.o



# SOURCE FILES　　（OBJSの.oを.cに置換え）
SRCS := ex02.c


# COMPILER TYPE
CC := gcc


# COMPILER OPTION
CFLAGS := -g -Wall -Wextra -DDEBUG=1



# オプションの例
# -g: デバッグ情報付与
# -Wall: 全ての警告を表示
# -lm: 三角関数などの算術ライブラリlabm.aをリンク
# -pthread: pthreadsライブラリをリンク
# -D: definition for '#if DEBUG=1'


# DYNAMIC LIBRARY
# LDFLAGS := -lpthread



# MAKE ALL (PHONY TARGET)
.PHONY: all
all: $(TARGET)


# LINK OBJECTS
$(TARGET): $(OBJS)
	$(cc) $(CFLAGS) -o $@ $(OBJS) $(LDFLAGS)




# COMPILE SOURCES
./%.o: ./%.c
	$(CC) $(CFLAGS) -c $<

# サフィックスルール'.c.o: '（$^には～.cファイルを指定し同じ名前の～.oファイルを作成）
# などもよく使われます. 


# UPDATE HEADER FILE
$(OBJS): *.h


# CLEAN FILES (PHONY TARGET)
.PHONY: clean
clean: 
	rm -f *.o *~ $(TARGET)

