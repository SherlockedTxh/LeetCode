class Solution(object):
    def deckRevealedIncreasing(self, deck):
        """
        :type deck: List[int]
        :rtype: List[int]
        """
        maxindex = len(deck)
        ans = []
        ans.append(maxindex)
        if(maxindex <= 1):
            return deck
        else :
            for i in range(2,maxindex):
                if(maxindex-i+1>1):
                    cnt = ans.pop()
                    ans.insert(0,maxindex-i+1)
                    ans.insert(0,cnt)
                else :
                    ans.insert(0,1)

        deck.sort()
        if maxindex==2:
            return deck
        res = []
        for i in range(maxindex):
            res.append(deck[ans[i]-1])
        return res