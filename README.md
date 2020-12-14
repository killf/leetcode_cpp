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
  * 二叉搜索树的中序遍历是一个递增序列
* 排序算法
  * 插入排序
* C++中常用数据结构和算法
  * map->红黑树，具有自动排序功能
  * 排序:sort
  * 翻转:reverse