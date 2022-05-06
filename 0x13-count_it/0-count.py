#!/usr/bin/python3
"""0x13. Count it!"""

import requests


def count_words(subreddit, word_list, after='null', word_count=[]):
    """Counts words in word_list of given subreddit"""
    url = "https://www.reddit.com/r/" + subreddit + "/hot.json"
    new = []
    if after == 'null':
        [new.append(x) for x in word_list if x not in new]
        word_list = new
    headers = {
            'User-Agent': 'My User Agent 1.0',
    }
    after = {
        "after": after
    }
    response = requests.get(url, headers=headers, allow_redirects=False,
                            params=after)
    try:
        current = response.json()['data']['children']
        after = response.json()['data']['after']
    except Exception:
        return
    for i in current:
        name = i['data']['title'].lower()
        for j in word_list:
            if j.lower() in name:
                word_count.append(j.lower())
    if after not in ["NULL", 'null', None, "None"]:
        return count_words(subreddit, word_list, after, word_count)
    else:
        word_dict = {i: word_count.count(i) for i in word_count}
        word_dict = {k: v for k, v in sorted(word_dict.items(),
                                             key=lambda item: item[1],
                                             reverse=True)}
        if len(word_dict) != 0:
            for k, v in word_dict.items():
                if v != 0:
                    print("{}: {}".format(k, v))
    return
