#!/usr/bin/python3
"""0x00. Lockboxes"""


def canUnlockAll(boxes):
    """Checks if all boxes can be opened"""
    keys = [0]
    for key in keys:
        for new in boxes[key]:
            if new not in keys and new <= len(boxes) - 1:
                keys.append(new)
    if len(boxes) == len(keys):
        return True
    else:
        return False
