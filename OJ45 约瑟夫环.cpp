//
// Created by ProMoriarty on 2017/9/8.
//
/**
 *  约瑟夫环
 *  题目描述
每年六一儿童节,牛客都会准备一些小礼物去看望孤儿院的小朋友,今年亦是如此。
 HF作为牛客的资深元老,自然也准备了一些小游戏。其中,有个游戏是这样的:首先,让小朋友们围成一个大圈。
 然后,他随机指定一个数m,让编号为0的小朋友开始报数。
 每次喊到m-1的那个小朋友要出列唱首歌,然后可以在礼品箱中任意的挑选礼物,并且不再回到圈中,从他的下一个小朋友开始,
 继续0...m-1报数....这样下去....直到剩下最后一个小朋友,可以不用表演,
 并且拿到牛客名贵的“名侦探柯南”典藏版(名额有限哦!!^_^)。请你试着想下,哪个小朋友会得到这份礼品呢？(注：小朋友的编号是从0到n-1)
 */
 模拟整个过程，复杂度为O(NM)。可以用数学方法来求解：
 把问题重新描述一下：N个人（编号0~(N-1))，从0开始报数，报到(M-1)的自杀，剩下的人继续从0开始报数。求最后自杀者的编号。
 N个人编号如下：
 
 第一个自杀的人是（M-1）%N，例如上图中，41个人中，报到3的人自杀，则字一个自杀的人的编号是（3-1）%41=2。编号（M-1)%N自杀后，剩下的人排列如下：
 
 有人自杀后，下一个位置M又从零开始报数，因此环应该如下：
 
 将上面的排列顺序重新编号：
 
 问题变为（N-1）个人，报到为（M-1）的人自杀，问题规模减小了。这样一直进行下去，最后剩下编号为0的人。用函数表示：
 F(1)=0
 当有2个人的时候（N=2），报道（M-1）的人自杀，最后自杀的人是谁？应该是在只有一个人时，报数时得到的最后自杀的序号加上M，因为报到M-1的人已经自杀，只剩下2个人，另一个自杀者就是最后自杀者，用函数表示：
 F(2)=F(1)+M
 可以得到递推公式：
 F(i)=F(i-1)+M
 因为可能会超出总人数范围，所以要求模
 F(i)=(F(i-1)+M)%i
 有了递推公式就可以在O（N）时间求出结果：


class Solution {
public:
    int LastRemaining_Solution(unsigned int n, unsigned int m)
    {
        if(n==0)
            return -1;
        if(n==1)
            return 0;
        else
            return (LastRemaining_Solution(n-1,m)+m)%n;
    }
};

class Solution {
public:
    int LastRemaining_Solution(unsigned int n, unsigned int m)
    {
        if(n<1 || m<1){ return -1;}
        int last = 0;
        for(int i=2;i<=n;i++){
            last = (last+m)%i;
        }
        return last;
    }
};
