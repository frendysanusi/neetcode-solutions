class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        res = []

        def backtrack(open_cnt: int, close_cnt: int, curr: str):
            if len(curr) == 2*n:
                res.append(curr)
                return
            
            if open_cnt < n:
                backtrack(open_cnt + 1, close_cnt, curr + '(')
            
            if close_cnt < open_cnt:
                backtrack(open_cnt, close_cnt + 1, curr + ')')
        
        backtrack(0, 0, "")
        return res