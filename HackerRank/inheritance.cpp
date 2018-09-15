/*
*
* Tag: Inheritance
*
*/
class Student :  public Person{
	private:
		vector<int> testScores;  
	public:
        /*	
        *   Class Constructor
        *   
        *   Parameters:
        *   firstName - A string denoting the Person's first name.
        *   lastName - A string denoting the Person's last name.
        *   id - An integer denoting the Person's ID number.
        *   scores - An array of integers denoting the Person's test scores.
        */
        Student(string firstName, string lastName, int identification, vector<int> scores)
        : Person(firstName, lastName, identification){
            this->testScores = scores;
        }

        /*	
        *   Function Name: calculate
        *   Return: A character denoting the grade.
        */
        char calculate(){
            double avg = 0;
            int n = testScores.size();
            for(int i = 0; i < n; ++ i)
                avg += testScores[i];
            avg = avg/n;
            char res = 0;
            if(avg < 40)
                res = 'T';
            else if(avg < 55)
                res = 'D';
            else if(avg < 70)
                res = 'P';
            else if(avg < 80)
                res = 'A';
            else if(avg < 90)
                res = 'E';
            else
                res = 'O';
            return res;
        }
};
