class ShootingGame(object):
    def findProbability(self, p):
        a = p * 1.0 / 1000000;
        ans = 0;
        if p != 1000000:
            ans = a / (1 - a)
        if p == 1000000 or ans > 1.0:
            ans = -1.0
        return ans
