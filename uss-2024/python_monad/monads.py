# base class for our monad
class Option:
    def __init__(self):
        pass

    def is_some(self):
        return isinstance(self, Some)
    
    def is_none(self):
        return isinstance(self, NoneType)

# values are wrapped in Some if they are valid
class Some(Option):
    def __init__(self, value):
        self.value = value

    def __repr__(self):
        return f'Some({self.value})'

class NoneType(Option):
    def __repr__(self):
        return 'None'

# function to wrap values in the Option type
def option_return(value):
    return Some(value)

# monadic bind operation to apply func to the optional value
# propagates none if opt is of NoneType
def option_bind(opt, func):
    if opt.is_some():
        return func(opt.value)

    return NoneType()

def safe_divide(x, y):
    if y == 0:
        return NoneType()
    
    return Some(x / y)

def option_demo():
    opt_val = option_return(10)
    print(f'Initial value: {opt_val}')

    result1 = option_bind(opt_val, lambda x: safe_divide(x, 2))
    print(f'Divided by 2: {result1}')

    result2 = option_bind(opt_val, lambda x: safe_divide(x, 0))
    print(f'Divided by 0: {result2}')

    result3 = option_bind(result2, lambda x: safe_divide(x, 2))
    print(f'Trying to operate on NoneType: {result3}')

option_demo()
