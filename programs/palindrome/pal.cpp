#include <iostream>
#include <string>

class Palindrome
{
public:
    static bool isPalindrome(const std::string& word)
    {
        bool final = true;
        std::string temp = "";
        int i=0;
        char max;
        char min;

        for(i=0; i < word.length(); i++)
        {
            temp += tolower(word[i]);
        }

        for(i=1; i < temp.length(); i++)
        {
            max = temp[(temp.length() - i)];
            min = temp[(i -1 )];

            if(max != min)
            {
                final = false;
            }
        }

        return final;
    }
};

#ifndef RunTests
int main()
{
    std::cout << Palindrome::isPalindrome("DeLeveled")  << std::endl;;
    std::cout << Palindrome::isPalindrome("Dled")  << std::endl;;
    std::cout << Palindrome::isPalindrome("racecar")  << std::endl;;
    std::cout << Palindrome::isPalindrome("raceeecar")  << std::endl;;
}
#endif
