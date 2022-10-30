# Array-Optimization-using-Dynamic-Programming
-Built a function 'Max_min_grouping' that takes in an Array(A) and Number of Partitions (M)
-The function divides the array into M subgroups and calculates the sum for each subgroup for several grouping combinations
-For example: if len(A)=12 and M=3, the division will be (4,4,4), (3,4,5), and many more
-The function uses Dynamic Programming to do comparisons and select the most optimal subgrouping, such that the subgroup that had the minimum sum will now have its maximum possible value
-The program uses a pointer P[i][j] to store the predecessor of the current element c[i][j] so that the predecessor can be accessed efficiently
