- [x] 3     Longest Substring Without Repeating Characters		
- [x] 30    Substring with Concatenation of All Words 	  
- [x] 76    Minimum Window Substring	  	  
- [x] 209   Minimum Size Subarray Sum
- [x] 239   Sliding Window Max  ( Recommanded )
- [x] 340   Longest Substring with At Most K Distinct Characters   
- [x] 395   Longest Substring with At Least K Repeating Characters			  
- [x] 424   Longest Repeating Character Replacement			  ( Recommanded) 
- [x] 438   Find All Anagrams in a String
- [x] 632   Smallest Range Covering Elements from K Lists ( Hard )
- [x] 862   Shortest Subarray with Sum at Least K ( Hard, follow up from 209, only this time with negative values )
- [x] 904   Fruit Into Baskets
- [x] 992   Subarrays with K Different Integers  ( Hard )
- [x] 1234  Replace the Substring for Balanced String
- [x] 1248  Count Number of Nice Subarrays
- [x] 1493  Longest Subarray_of_1's_After_Delete_One_Element (cool)
- [x] 1574  Shortest Subarray to be Removed to Make Array Sorted 
- [x] 1658	Minimum Operations to Reduce X to Zero ( similar to two sum, hash)
- [x] 1888  Mininum Number of Flips to Make the Binary String Alternation

## TODO			  
- [ ] 480   Sliding Window Median			  
- [ ] 567   Permutation in String			    
- [ ] 727   Minimum Window Subsequence    
- [ ] 978   Longest Turbulent Subarray	  
- [ ] 995	Minimum Number of K Consecutive Bit Flips			     
- [ ] 1004	Max Consecutive Ones III			  
- [ ] 1040	Moving Stones Until Consecutive II		   
- [ ] 1052	Grumpy Bookstore Owner			  
- [ ] 1074	Number of Submatrices That Sum to Target			  
- [ ] 1100	Find K-Length Substrings With No Repeated Characters	  
- [ ] 1151	Minimum Swaps to Group All 1's Together  
- [ ] 1176	Diet Plan Performance  
- [ ] 1208	Get Equal Substrings Within Budget	  		
- [ ] 1358  Number of Substrings Containing All Three Characters
- [ ] 1423	Maximum Points You Can Obtain from Cards   			
- [ ] 1438	Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit	
- [ ] 1456	Maximum Number of Vowels in a Substring of Given Length			  
- [ ] 1498	Number of Subsequences That Satisfy the Given Sum Condition			  
- [ ] 1499	Max Value of Equation			  


Binary Subarrays With Sum
Fruit Into Baskets

For 3. Longest Substring Without Repeating Characters:
```
class Solution:
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        lookup = collections.defaultdict(int)
        l, r, counter, res = 0, 0, 0, 0
        while r < len(s):
            lookup[s[r]] += 1
            if lookup[s[r]] == 1:
                counter += 1
            r += 1
            while l < r and counter < r - l:
                lookup[s[l]] -= 1
                if lookup[s[l]] == 0:
                    counter -= 1
                l += 1
            res = max(res, r - l)
        return res
```

### For 395. Longest Substring with At Most K Distinct Characters:

Follow up For 159. Longest Substring with At Most Two Distinct Characters, set k = 2

```
class Solution(object):
    def lengthOfLongestSubstringKDistinct(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        lookup = collections.defaultdict(int)
        l, r, counter, res = 0, 0, 0, 0
        while r < len(s):
            lookup[s[r]] += 1
            if lookup[s[r]] == 1:
                counter += 1
            r += 1   
            while l < r and counter > k:
                lookup[s[l]] -= 1
                if lookup[s[l]] == 0:
                    counter -= 1
                l += 1
            res = max(res, r - l) 
        return res
```