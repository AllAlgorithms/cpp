This algorithm find's the minimum number of status check require inorder to cover maximum number of process running at a time.
statusCkeckG.cpp is designed in a Greedy manner.
In this problem start time and finish time of each process is given.
And we've to sort in non-decreasing order of their finish time.
Then check at what time statusCheck() needed to be invoked such that the number of invocation of statusCheck() is minimum.

statusCheck() is a function which collects the some information about process.

Inputs are:
'start time', 'finish time', 'type of process'

'type of process':
it can be 'normal' represented as 'N'
or it can be 'sensitive' represented as 'S'

given condition that for each sensitive process there must be atleast on statusCheck().