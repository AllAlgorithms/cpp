/**
 * 
 *@gaurav yadav
 
	 Maintain a stack
	a. If stack is empty  heights[stack.top()] <= heights[i])
		push this i into stack.
 	b. Else keep popooing from stack till value at i at top of stack is 
		less than value at current index.
	c. While popping calculate area
		if stack is empty 
			 area = i * heights[top];
			it means that till this point value just removed has to be smallest element
  		if stack is not empty 
			area = heights[top] * (i - stack.top() - 1);
			
 * Finally return maxArea
 * Time complexity is O(n)
 * Space complexity is O(n)
 */
class Solution {
public:

    int largestRectangleArea(vector<int>& heights) {
        int area = 0;
        int maxArea = 0;
        stack <int> s;
        int i;
        for (i = 0; i < heights.size();) {
            if (s.empty() || heights[s.top()] <= heights[i]) {
                s.push(i++);
            }
            else {
                int top = s.top();
                s.pop();
                if (s.empty()) {
                    area = i * heights[top];
                }
                else {
                    area = heights[top] * (i- s.top() -1); 
                }
                if (area > maxArea)
                    maxArea = area;
            }
        }

        while (!s.empty()) {
            int top = s.top();
            s.pop();
            if (s.empty()) {
                area = i * heights[top];
            }
            else {
                area = heights[top] * (i- s.top() -1); 
            }
            if (area > maxArea)
                maxArea = area;
        }
        return maxArea;
    }
};
