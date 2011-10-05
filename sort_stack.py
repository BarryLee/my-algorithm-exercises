
def sort_stack(stack):
    sz = len(stack)
    if not sz: return

    for i in range(sz):
        sort_stack_once(stack)

def sort_stack_once(stack):
    top = stack.pop()
    
    if not len(stack):
        stack.append(top)
        return 

    if stack[-1] > top:
        nt = stack.pop()
        stack.append(top)
        top = nt 

    sort_stack_once(stack)
    stack.append(top)

if __name__ == '__main__':
    from random import randint
    sz = 900
    stack = [randint(0,100) for i in range(sz)]
    #print stack
    old_stack = stack[:]
    
    sort_stack(stack)
    #print stack
    old_stack.sort()
    assert old_stack == stack
