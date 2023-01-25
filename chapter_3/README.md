# Lex automation scanner program
contributed by <`williamchangTW`>

##### Target
- 了解 `Lex` 輸入文件的格式
- 使用 `Lex` 自動生成掃描程序的方法

##### Background
- 正規表示式的編寫方法
- 了解標示符和關鍵字
- `GNU Flex` 作為 scanner program

## Files
- `sample.txt`: 作為最終產生可執行檔案的輸入
- `define.h`: Token 檔案的定義
- `scan.txt`: 作為 `flex` 產出 `lex.yy.c` 的來源檔
- `lex.yy.c`: 由 `flex` 所產生出來的，再由 `gcc` 產出可執行檔

### Token
~~~=table
1 | {...}                        | 大括號內的是注釋
2 | read                         | 標準輸入，關鍵字
3 | write                        | 標準輸出，關鍵字
4 | if ... then ... else ... end | if 和 else 判斷式，用 end 作為結束，共 4 個關鍵字
5 | repeat ... until             | 類似於 do ... while 語句，共 2 關鍵字
6 | <, =                         | 運算符
7 | +, -, *, /                   | 算術運算符
8 | :=                           | 賦值運算符
9 | 正整數                        | 數字 0 ~ 9
10| 標示符號                      | 大小寫字母
11| ;                            | 語句的結束
~~~

### Code flow
- 第一部分: 
    - 在 `%{` 與 `}%` 中間加入 C code
    - 定義 **換行(newline)** 與 **空白(whitespace)** 的正規表示式
- 第二部分:
    - 比較運算符、算術運算符等規則
    - 匹配換行規則，匹配成功就統計行數
    - 匹配空白規則，匹配成功就忽略
    - 匹配註釋的開始符號後，開始編譯 C code，直到結束符號
    - 使用 `Lex` 正規表示式中的 **“.”** 來匹配其他任何符號
- 第三部分:
    - 直接插入 C code 檔案

### Functions
- `main`: 主程序，開啟檔案後做後續統計關鍵字及標示符號等操作
- `id2keyword`: 將標示符號轉換成對應的關鍵字類型，尚未完成
- `stat`: 根據 `tt` 參數輸入的結果，並統計關鍵字跟標示符號
- `output`: 輸出統計結果

### Usage
Follow below commands:
~~~=command
flex scan.txt
gcc lex.yy.c
./a.out sample.txt
~~~

#### Trouble shooting: Undefined symbols for architecture arm64
> Error log:
> Undefined symbols for architecture arm64:
>  "_yywrap", referenced from:
>      _yylex in lex-efe5f7.o
>      _input in lex-efe5f7.o
>ld: symbol(s) not found for architecture arm64

- Solution1: provide a link option
將 `gcc` 加上 link 選項:
~~~=command
gcc lex.yy.c -ll
~~~
- Solution2: skip the check for `_yywrap` symbols in source file
在 `flex` 的來源檔中加入下面字串，略過 `yywrap` 的處理
~~~=lex
%option noyywrap
~~~
