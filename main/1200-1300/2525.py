class Solution:
    def categorizeBox(self, l: int, w: int, h: int, m: int) -> str:
        ans = ""
        if l >= 10 **4 or w >= 10 **4 or h >= 10 **4 or l * w * h >= 10 **9:
            ans += "Bulky"
        if m >= 100:
            ans += "Heavy"
        if ans == "":
            return "Neither"
        if ans == "BulkyHeavy" or ans == "HeavyBulky":
            return "Both"
        if ans == "Bulky":
            return "Bulky"
        if ans == "Heavy":
            return "Heavy"