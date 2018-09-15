/*
*
* Tag: Design
*/
class Solution {
public:
    char *m_pData;
    Solution() {
        this->m_pData = NULL;
    }
    Solution(char *pData) {
        this->m_pData = pData;
    }

    // Implement an assignment operator
    Solution& operator=(const Solution &object) {
        // write your code here
        if (this != &object){
            if(m_pData){
                delete[] m_pData;
                m_pData = NULL;
            }
            if(!object.m_pData)
                return *this;
            m_pData = new char[strlen(object.m_pData)+1];
            strcpy(m_pData, object.m_pData);
        }
        return *this;
    }
};
