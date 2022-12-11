# Vanilla C Compiler

## Files
- `NFAFragmentStack.h`
- `RegexpToPost.h`
- `RegexpToNFA.h`
- `NFAFragmentStack.c`
- `RegexpToPost.c`
- `main.c`

## Definitions
### NFA

### Table 2-1
#### DFA domain
- `DFAlist`: DFA 狀態集合
- `length`: 集合中 DFA 狀態數量, 與前一項構成一個 linked list

### Table 2-2
#### DFAState domain
- `NFAlist`: NFA 狀態集合, 用於保存 DFA 狀態中的 NFA 狀態集合
- `NFAStateCount`: 集合中 NFA 狀態數量, 與前一項構成一個 linked list
- `firstTran`: 指向第一個轉換項目

#### Transform domain
- `TransformChar`: 狀態之間轉換的符號
- `DFAStateIndex`: DFA 狀態在 linked list 中的標示, 用於只是轉換的目標 DFA 狀態 NFA 狀態集合, 用於保存構造的子即予及生成新的 DFA 狀態
- `NFAlist`: NFA 狀態集合, 用於保存構造的子集以及生成新的 DFA 狀態
- `NFAStateCount`: 集合中的 NFA 狀態數量, 與前一項構成 linked list
- `NextTrans`: 指向下一個轉換

### Table 2-3
#### function name
- `CreateDFATransform`: 創造一個新的 DFA 轉換, 每當得到一個 closure 後可以調用此函數來創建一個 DFA 轉換
- `CreateDFAState`: 利用轉換作為參數建構一個新的 DFA 狀態, 同時將 NFA 狀態子集複製到新創見的 DFA 狀態中
- `NFAStateSubset`: 當一個子集構造完成後, 需要調用此函數來判斷是否需要為該子集創建一個新的 DFA 狀態
- `IsTransformExist`: 判斷 DFA 狀態的狀態 linked list 中是否已經存在一個字符的轉換, 每當一個 closure 後可以調用此函數來決定是新建一個轉換, 還是將 closure 合併到目前的轉換中
- `AddNFAStateArrayToTransform`: 將一個 NFA 集合合併到一個 DFA 轉換的 NFA 集合中, 並確保重複的 NFA 狀態只出現一次
- `Closure`: 使用二元樹的 prefix 遍歷算法求得一個 NFA 狀態的 closure
- `post2dfa`: 將解析樹的 postfix 轉換成 DFA