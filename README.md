参考灵茶山艾府 💭💡🎈 [EndlessCheng/codeforces-go: Golang 算法竞赛模板库 | Solutions to Codeforces by Go 💭💡🎈 (github.com)](https://github.com/EndlessCheng/codeforces-go)

由于算法知识点繁杂，将自己学习到的算法、做过的题目分类整理好是有必要的。

一个算法模板应当涵盖以下几点：

- 对该算法的基本介绍（核心思想、复杂度等）
- 参考链接或书籍章节（讲的比较好的资料）
- 模板代码（可以包含一些注释、使用说明）
- 模板补充内容（常见题型中的额外代码、建模技巧等）
- 相关题目链接（模板题、经典题、思维转换题等）

算法目录：

- [集合论与位运算](https://leetcode.cn/circle/discuss/CaOJ45/)

- 前缀 和 & 差分 

- 二分

- 构造

- 排序

  1. 选择排序
  2. 冒泡排序
  3. 插入排序
  4. 快速排序
  5. 归并排序
  6. 桶排序
  7. 基数排序
  8. 推排序
  9. 希尔排序

- 数据结构
  - [单调栈](https://github.com/Surplus-han/Basic__algorithm/blob/main/main/stack.cpp)
  - [链表](https://github.com/Surplus-han/Basic__algorithm/blob/main/main/ListNode.py)
  - 哈希表
  - 单调队列
    - 二维单调队列
  - 双端队列
  - 堆（优先队列）heap.go
    - 支持修改、删除指定元素
  - [稀疏表（ST 表）sparse_table.go](https://github.com/EndlessCheng/codeforces-go/blob/master/copypasta/sparse_table.go)
  - 树状数组 
    - 差分树状数组（支持区间加、区间求和）
  - 线段树 
    - 延迟标记（懒标记）
    - 动态开点
    - 线段树合并
    - 线段树分裂
    - 持久化（主席树）
  - 二叉搜索树 & 平衡树
  - 树状数组
  
- 字符串 strings.go
  - 字符串哈希
  - KMP
    - 最小循环节
  - 扩展 KMP（Z algorithm）
  - 最小表示法
  - 最长回文子串
    - Manacher 算法
  - 后缀数组（SA）
  - 后缀自动机
  - 字典树 t
    - 持久化
    - AC 自动机
  - 异或字典树 
    - 持久化
    - Hack：构造一组数据，最大化树上的节点数
  
- 数学
  - 位运算
  - gcd/lcm
  - 二进制集合操作
  - 快速幂
  - [埃氏筛 & 欧拉筛] 
  - 数论
  - 复数
  - 组合数学
  - 线性代数
  - 线性规划
  - 概率论
  - 博弈论
  - 数值算法
  - 杨氏矩阵
  
- 动态规划 dp.cpp
  - 背包
    - 0-1 背包
    - 完全背包
    - 多重背包
      - 二进制优化
      - 单调队列优化
    - 分组背包
    - 树上背包（依赖背包）
    - 字典序最小方案
  - 线性 DP
    - 最大子段和
    - LCS
    - LPS
    - LIS
      - 狄尔沃斯定理
    - LCIS
    - 长度为 m 的 LIS 个数
    - 本质不同子序列个数
  - 区间 DP
  - 环形 DP
  - 状压 DP
    - 旅行商问题（TSP）
    - 高维前缀和（SOS DP）
    - 插头 DP
  - 数位 DP
  - 倍增优化 DP
  - 斜率优化 DP（CHT）
  - 树形 DP
    - 树的直径个数
    - 在任一直径上的节点个数
    - 树上最大独立集
    - 树上最小顶点覆盖
    - 树上最小支配集
    - 树上最大匹配
    - 换根 DP（二次扫描法）
  
- 图论
  - 图的遍历（bfs/dfs)
  - 拓扑排序
  - 欧拉回路和欧拉路径
    - 无向图
    - 有向图
  - 割点
  - 割边（桥）
  - 双连通分量（BCC）
    - v-BCC
    - e-BCC
  - 最短路
    - Dijkstra
    - SPFA（队列优化的 Bellman-Ford）
      - 差分约束系统
    - Floyd-Warshall
    - Johnson
    - 0-1 BFS（双端队列 BFS）
    - 字典序最小最短路
    - 同余最短路
  - 最小环
  - 最小生成树（MST）
    - Kruskal
    - Prim
  - 单度限制最小生成树
  - 次小生成树
  - 曼哈顿距离最小生成树
  - 最小差值生成树
  - 最小树形图
    - 朱刘算法
  - 二分图判定（染色）
  - 二分图找奇环
  - 二分图最大匹配
    - 匈牙利算法
  - 带权二分图最大完美匹配
    - Kuhn–Munkres 算法
  - 拓扑排序
  - 强连通分量（SCC）
    - Kosaraju
    - Tarjan
  - 2-SAT
  - 基环树
  - 最大流
    - Dinic
    - ISAP
    - HLPP
  - 最小费用最大流
    - SPFA
    - Dijkstra
  - 三元环计数
  - 四元环计数
  - 仙人掌
  - 树上问题 graph_tree.go
    - 直径
    - 重心
      - 点分治
    - 最近公共祖先（LCA）
      - 倍增
      - ST 表
      - Tarjan
      - 树上差分
    - 重链剖分（HLD）
    - 长链剖分
    - 树上启发式合并（DSU）
    - 树分块
    - Prufer 序列
  
- 其他
  - 位运算笔记
    - bitset
    - 区间位运算 trick（含 GCD）
    
  - 二分 三分 
    - 0-1 分数规划
    - 整体二分
    
  - 搜索
    - 枚举排列
    - 枚举组合
    - 生成下一个排列
    - 康托展开
    - 逆康托展开
    - 枚举子集
      - Gosper's Hack
    - 折半枚举（Meet in the middle）
      - 超大背包问题
    
    

