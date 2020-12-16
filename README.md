* 贪心算法：将全局最优问题转为局部最优
* 数学方法：
  * 周期性问题转换为数论（余数）问题
  * 递归推理问题可以转换为数学问题
* 位运算
  * 异、或、非、异或
  * 消除最后一个1：x & (x - 1)，可用于判断1的个数
  * 移位运算
  * 加法运算：异或->相加后的结果，与->相加后的进位
  * 前导0的掩膜：
    ```
    n |= n >> 1; 
    n |= n >> 2; 
    n |= n >> 4; 
    n |= n >> 8; 
    n |= n >> 32;
    ```
* 搜索：
  * 广度优先
  * 深度优先
* 树
  * 二叉搜索树的中序遍历是一个递增序列，左边的节点比根节点小，右边的节点比根节点大
* 排序算法
  * 插入排序
* C++中常用数据结构和算法
  * map->红黑树，具有自动排序功能
  * 排序:sort
  * 翻转:reverse
* 哈希算法
  * 简单hash:用一个数组表示的hash
  * 普通hash:用n个链表表示，头指针存放到数组中
* 堆
  * 用于计算topk，可用于排序
  * 以数组作为存储结构
  * 根节点最小(大)，换句话就是当前节点比子节点小(大)
* LRU
  * 最近最少未使用算法，常用于做缓存
  * 总是保存最近使用的数据，隐含了时间概念
  * 实现方式:Hash表+双链表
* 性能优化技巧
  * 减小函数调用开销
* 解题思路
  * 分析问题，理清流程
  * 化简问题，等价变换
  * 发现问题，解决问题
  * 代码实现，边界测试
  * 代码优化，整理思路