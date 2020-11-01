#pragma once
// this is a general solution case that can be inherited by different children class
#include<iostream>

class Solution
{
private:
	
public:
	Solution()
	{}
	~Solution()
	{}
	virtual void run() const = 0;

};