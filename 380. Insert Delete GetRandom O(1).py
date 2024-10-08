import random
class RandomizedSet:
    def __init__(self):
        self.set = set()

    def insert(self, val: int) -> bool:
        if val in self.set:
            return False
        self.set.add(val)
        return True

    def remove(self, val: int) -> bool:
        if val not in self.set:
            return False
        self.set.remove(val)
        return True

    def getRandom(self) -> int:
        x = random.randint(0, len(self.set) - 1)
        for i in self.set:
            if not x:
                return i
            x -= 1
