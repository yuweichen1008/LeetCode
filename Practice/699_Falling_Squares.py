def fallingSquares(self, positions):
    height = [0] # Y-axis
    pos = [0] # X-axis
    res = []
    max_h = 0
    for left, side in positions:
        i = bisect.bisect_right(pos, left)
        j = bisect.bisect_left(pos, left + side)
        high = max(height[i - 1:j] or [0]) + side
        pos[i:j] = [left, left + side]
        height[i:j] = [high, height[j - 1]]
        max_h = max(max_h, high)
        res.append(max_h)
    return res