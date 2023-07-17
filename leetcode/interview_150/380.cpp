// ��ϣ��+�߳�����
// https://leetcode.cn/problems/insert-delete-getrandom-o1/description/?envType=study-plan-v2&envId=top-interview-150

class RandomizedSet {
public:
    RandomizedSet() {

    }
    
    bool insert(int val) {
        if(m.count(val)){
            return false;
        }
        int index = nums.size();
        nums.emplace_back(val);
        m[val] = index;
        return true;
    }
    
    bool remove(int val) {
        if(!m.count(val)){
            return false;
        }
        // ��Ҫɾ����Ԫ�ػ����������һ��λ��
        int index = m[val];
        int last = nums.back();
        nums[index] = last;
        m[last] = index;
        nums.pop_back();
        m.erase(val);
        return true;
    }
    int getRandom() {
        int randIndex = rand() % nums.size();
        return nums[randIndex];
    }
private:
    unordered_map<int,int>m;
    vector<int>nums;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */