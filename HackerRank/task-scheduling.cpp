/*
*
* Tag: Data Structure (Segment Tree)
* Time: O(nlgn)
* Space: O(n)
*/
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

class SegTree
{
public:
    SegTree(int left, int right, const vector<int>& original_data)
    {
        this->left = left;
        this->right = right;
        this->lazy_flag = 0;
        left_tree = right_tree = NULL;
        if (left == right)
        {
            this->value = this->max_value = original_data[left];
        }
        else
        {
            mid = (left + right) / 2;
            left_tree = new SegTree(left, mid, original_data);
            right_tree = new SegTree(mid + 1, right, original_data);
            push_up();
        }
    }
    void modify(int left, int right, int m_value)
    {
        if (this->left == left && this->right == right)
        {
            leaf_modify(m_value);
        }
        else
        {
            push_down();
            if (left <= mid)
            {
                if (right >= mid + 1)
                {
                    left_tree->modify(left, mid, m_value);
                    right_tree->modify(mid + 1, right, m_value);
                }
                else
                {
                    left_tree->modify(left, right, m_value);
                }
            }
            else
            {
                right_tree->modify(left, right, m_value);
            }
            push_up();
        }
    }
    int query(int left, int right)
    {
        if (this->left == left && this->right == right)
        {
            return this->max_value;
        }
        else
        {
            push_down();
            if (left <= mid)
            {
                if (right >= mid + 1)
                {
                    int max_value_l = left_tree->query(left, mid);
                    int max_value_r = right_tree->query(mid + 1, right);
                    return max(max_value_l, max_value_r);
                }
                else
                {
                    return left_tree->query(left, right);
                }
            }
            else
            {
                return right_tree->query(left, right);
            }
        }
    }
private:
    int left, right, mid;
    SegTree *left_tree, *right_tree;

    int value, lazy_flag, max_value;

    void push_up()
    {
        this->max_value = max(this->left_tree->max_value, this->right_tree->max_value);
    }
    void push_down()
    {
        if (this->lazy_flag > 0)
        {
            left_tree->leaf_modify(this->lazy_flag);
            right_tree->leaf_modify(this->lazy_flag);
            this->lazy_flag = 0;
        }
    }
    void leaf_modify(int m_value)
    {
        this->lazy_flag += m_value;
        this->max_value += m_value;
    }
};

vector<int> vec_d, vec_m, vec_idx, vec_rank, vec_d_reorder;

int cmp(int idx_x, int idx_y)
{
    return vec_d[idx_x] < vec_d[idx_y];
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        int d, m;
        scanf("%d%d", &d, &m);
        vec_d.push_back(d);
        vec_m.push_back(m);
        vec_idx.push_back(i);
    }

    sort(vec_idx.begin(), vec_idx.end(), cmp);
    vec_rank.assign(T, 0);
    vec_d_reorder.assign(T, 0);
    for (int i = 0; i < T; i++)
    {
        vec_rank[ vec_idx[i] ] = i;
    }
    for (int i = 0; i < T; i++)
    {
        vec_d_reorder[i] = -vec_d[ vec_idx[i] ];
    }

    SegTree tree(0, T-1, vec_d_reorder);

    for (int i = 0; i < T; i++)
    {
        tree.modify(vec_rank[i], T-1, vec_m[i]);
        int ans = tree.query(0, T-1);
        printf("%d\n", max(0,ans));
    }
}
