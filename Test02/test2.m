while 1
    r = randi(100);
    unsolved = 1;
    guesscount = 0;
    while unsolved
        i = input('Please guess a number ');
        guesscount = guesscount + 1;
        if i == r
            unsolved = 0;
            disp('your guess is correct!');
            disp({'it took you ', guesscount,'guesses to win.'});
            break;
        else
            if i < r
                disp('Your guess is too low');
            else
                if i > r
                    disp('your guess is too high');
                else
                    disp ('your input was not understood');
                end
            end
      end
    end
end
