import sys

def input_data():
    try: 
        for line in sys.stdin:
            print(line, end='')
        return 0
    except Exception as err:
        print(f'Error: {err}', file=sys.stdout)
        return 1
        
if __name__ == '__main__':
    print('Input data:')
    exit_code = input_data()
    print('')
    sys.exit(1)
    