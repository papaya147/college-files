def share_21BDS0340(total_p, p_share):
    r = total_p - round(total_p *  p_share / 100)
    if r == 0:
        r = 'No pens left to share'
    return r

n = int(input())
if n < 0:
    print('Pens should be >= 0')
else:
    p = int(input())
    if p < 0 or p > 100:
        print('Percentage should be 0 to 100')
    else:
        print(share_21BDS0340(n, p))