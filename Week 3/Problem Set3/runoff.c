//核心逻辑：如果没有候选人的票数超过总票数的一半，就淘汰得票数最少的候选人，
//         然后将其票数转移到其他候选人，然后继续下一轮投票，如此循环直到找到胜者或者全部平局。


#include <cs50.h>
#include <stdio.h>
#include <string.h>
//这两行代码定义了最大的投票人数和最大的候选人数。
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

//定义了一个二维数组，用来存储每个投票者对候选人的排名。
int preferences[MAX_VOTERS][MAX_CANDIDATES];

//定义了一个新的数据类型 candidate，表示一个候选人，包括他的名字、得票数和他是否已经被淘汰。
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

//定义了一个 candidate 类型的数组，用来存储所有的候选人。
candidate candidates[MAX_CANDIDATES];

int voter_count;      //投票人数
int candidate_count;   //候选人数

bool vote(int voter,int rank, string name);    //声明了一个函数，这个函数用于记录一次投票。
void tabulate(void);                           //这个函数用于统计每个候选人的得票数。
bool print_winner(void);                       //这个函数用于打印获得胜利者的名字。
int find_min(void);                            //这个函数用于找到得票数最少的候选人的得票数。
bool is_tie(int min);                          //这个函数用于检查是否所有的候选人的得票数都和最小的得票数相等，也就是检查是否是平局。
void eliminate(int min);                       //这个函数用于淘汰得票数最少的候选人。

int main(int argc, string argv[])
{
    //这个 if 语句检查命令行参数的个数。如果没有足够的参数，那么就打印一个错误信息并退出程序。
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    candidate_count = argc - 1; //这行代码计算出候选人的数量，等于命令行参数的数量减一（因为第一个参数是程序的名字）。

    //这个 if 语句检查候选人的数量是否超过了最大的候选人数。如果超过了，那么就打印一个错误信息并退出程序。
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }

    //这个 for 循环初始化所有的候选人。每个候选人的名字是一个命令行参数，他们一开始的得票数都是0，而且都没有被淘汰。
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    //这行代码询问用户投票者的数量。
    voter_count = get_int("Number of voters: ");

    //这个 if 语句检查投票人数是否超过了最大的投票人数。如果超过了，那么就打印一个错误信息并退出程序。
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    //这个 for 循环获取每个投票者的投票。每个投票者都需要输入他们对每个候选人的排名。
    for (int i = 0; i < voter_count; i++)
    {

        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    //这个 while 循环进行投票的各个阶段。每个阶段都包括统计得票数、打印获胜者、找到得票最少的候选人、检查是否是平局、淘汰得票最少的候选人等步骤。
    while (true)
    {

        //调用 tabulate 函数统计每个候选人的得票数。在这个阶段，只有未被淘汰的候选人的票数会被统计。
        tabulate();

        //调用 print_winner 函数尝试打印出胜利的候选人。如果存在一名候选人得票数超过一半，则其为胜者，函数会返回 true。
        bool won = print_winner();

        //这个 if 语句检查 print_winner 函数的返回值。如果有候选人已经获胜（print_winner 返回 true），那么 while 循环就结束。
        if (won)
        {
            break;
        }

//调用 find_min 函数找到还在竞选中的候选人的最小票数。
        int min = find_min();

       // 调用 is_tie 函数检查所有还在竞选中的候选人的票数是否都等于最小票数，也就是检查是否为平局。
        bool tie = is_tie(min);

//这个 if 语句检查是否为平局。如果是平局（is_tie 返回 true），那么就打印所有还在竞选中的候选人的名字，并结束 while 循环。
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

//如果没有候选人获胜，也不是平局，那么就调用 eliminate 函数淘汰得票数最少的候选人。
        eliminate(min);

//这个 for 循环将所有候选人的票数重置为0，为下一轮投票做准备。
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

bool vote(int voter, int rank, string name)
{
    for(int i=0;i<candidate_count;i++)
    {
        if(strcmp(candidates[i].name,name)==0)
        {
            preferences[voter][rank]=i;
            return true;
        }
    }
    return false;
}

void tabulate(void)
{
    for(int i=0; i<voter_count; i++)
    {
        for(int j=0;j<candidate_count;j++)
        {
            int e = preferences[i][j];
            if(candidates[e].eliminated==false)
            {
                candidates[e].votes++;
                break;
            }
        }
    }
    return;
}

bool print_winner(void)
{
    for(int i=0;i<candidate_count;i++)
    {
        if(candidates[i].votes > voter_count/2)
        {
            printf("%s\n",candidates[i].name);
            return true;
        }
    }
    return false;
}

int find_min(void)
{
    int min=MAX_VOTERS;
    for(int i=0;i<candidate_count;i++)
    {
        if(candidates[i].votes<min &&candidates[i].eliminated==false)
        {
            min=candidates[i].votes;
        }
    }
    return min;
}

bool is_tie(int min)
{
    for(int i=0;i<candidate_count;i++)
    {
        if(candidates[i].votes!=min &&candidates[i].eliminated==false)
        {
            return false;
        }
    }
    return true;
}

void eliminate(int min)
{
    for(int i=0;i<candidate_count;i++)
    {
        if(candidates[i].votes==min &&candidates[i].eliminated ==false)
        {
            candidates[i].eliminated=true;
        }
    }
    return;
}
