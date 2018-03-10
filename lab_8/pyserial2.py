import  serial
import time
import curses


def twoWayExample():
    while True:
        response = ''
        recieved = False

        ser = serial.Serial('/dev/ttyACM0', timeout=0.001, baudrate=9600)
        send = getch()
        print(send)
        ser.write(send.encode('ascii'))

        print('Message sent, waiting for response...')
        while not recieved:
            bytein = ser.read()
            while(bytein != b''):
                recieved = True
                response += bytein.decode('ascii')
                time.sleep(0.002)
                bytein = ser.read()

        print(response)

def lightControl(stdscr):
    # stdscr.nodelay(1)
    ser = serial.Serial('/dev/ttyACM0', timeout=0.001, baudrate=9600)

    while True:
        response = ''
        recieved = False

        c = stdscr.getch()
        while c == -1:
            c = stdscr.getch()
        
        # reset the screen
        stdscr.refresh()
        stdscr.addstr(chr(c) + ' sent, waiting for response...\n')

        ser.write(chr(c).encode('ascii'))

        while not recieved:
            bytein = ser.read()
            while(bytein != b''):
                recieved = True
                response += bytein.decode('ascii')
                time.sleep(0.003)
                bytein = ser.read()
        stdscr.clear()
        stdscr.addstr(response + '\n')
        ser.flush()
        curses.flushinp()

        # stdscr.move(0, 0)
        # time.sleep(.2)

if __name__ == "__main__":
    #twoWayExample()
    curses.wrapper(lightControl)