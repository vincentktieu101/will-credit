#include <cs50.h>
#include <stdio.h>

// good job with formating. this is something that a lot of beginners mess up
// and it shows that you're not a noob when you know how to format.
// i personally like to put my open curly braces on the same line that i init my
// function / if / while blocks but either works. if you work in an existing codebase,
// follow the code formating rules they use.

// ex: i do something like 
// if (True == True) {
//     printf("True");
// }

// in general try to separate your code in functions. it makes your code much more readible
// and easier to debug

int main(void)
{
    // i really like that you defined all your variables at the top
    // it makes your code easier to read when you want to figure out what
    // type a variable is. this is a good pattern in any language where you
    // have to define variables before you use them

    // your variables names should be consistent. pick either snake_case or camel_case
    // and always use all capitial letters + underscores for constant variables
    // Number => Number
    // checksum1 => checkSum1
    // checksum2 => checkSum2

    // different languages have different preferences. Javascript prefers camel case.
    // Python prefers snake case. In C, i dont think it matters just be consistent

    // look up how to change all variables names in vscode. super useful tool.

    // Obtain user input for credit card Number
    long Number;
    // Find first checksum
    // (sum of digits of twice every other digit from second to last)
    long Number2;
    long checkNum;
    long checksum1 = 0;
    long checksum2 = 0;
    long subtractor;
    long adder;
    long counter = 10;

    // you should make a const variable for this constant because you use it so often.
    // it's not recommended you keep typing it out because there's a high change you'll
    // accidentally make a typo and it makes it easier to change in one location if you need to
    // long CREDIT_MODULUS = 1000000000000000

    // most people don't use do while loops anymore. i would avoid using them. ill admit
    // this is a great use for a do while loop. i wouldn't use them ever tho
    // also move this block below your other definition statements for readibility
    do
    {
        Number = get_long("Number: ");
    }
    while (Number < 0);

    Number2 = Number;
    checkNum = Number;

    // you should probably make this a function in which you return the value of checksum1
    // then do something like
    // checksum1 = getCheckSum1(Number, counter)
    // checksum2 = getCheckSum2(Number, counter)
    // then you probably don't need variables adder or subtractor in your "main"
    // function because you can just calculate them within your new function
    // for getCheckSum1

    // i also have no idea how you're doing the calculations for checksum.
    // maybe you copied some algorithm online but i find this really confusing.
    // not a big deal though but it went over my head. sometimes there's a way
    // to rewrite it so it's easier to understand but if you were to come back
    // to this code after a week, this would probably look like gibberish to you too
    do
    {
        subtractor = Number % counter;
        adder = ((Number - subtractor) % (10 * counter));
        // Add the digits to create first checksum
        if (2 * adder / counter >= 10)
        {
            checksum1 = checksum1 + 1 + 2 * (adder / counter) % 10;
        }
        else
        {
            checksum1 = checksum1 + 2 * adder / counter;
        }
        Number = Number - subtractor - (adder);
        counter *= 100;
    }
    while (Number > 0);

    // make a new function for getCheckSum2 like mentioned above
    // Obtain second checksum
    // (sum of every other digit from last)
    counter = 10;
    do
    {
        adder = Number2 % (counter);
        subtractor = ((Number2 - adder) % (10 * counter));
        // Add the digits to create second checksum
        checksum2 = checksum2 + (adder / (counter / 10));
        Number2 = Number2 - subtractor - (adder);
        counter *= 100;
    }
    while (Number2 > 0);

    // since you only use check0 once, i would advise against making a new
    // variable for that. it can be annoying to pick good names for variables
    // and the variable name "check0" doesn't really help describe anything.
    // otherwise i think the way you named your variables are fine

    // Add both checksums and check if last digit = 0
    long check0 = checksum1 + checksum2;

    // do the following instead:
    // if (checksum1 + checksum2 == 0)
    if (check0 % 10 == 0)
    {
        // Check for card type
        // i realize that the "1000000000000000" number isn't the same for all if statements.
        // if it were then you could just calculate it once so you don't have to keep
        // calculating it.

        // for readibility you should do what you suggested and
        // do 10^14 or whatever so it's clear that the numbers are different
        if ((checkNum - (checkNum % 1000000000000000)) / 1000000000000000 == 4)
        {
            printf("VISA\n");
        }
        else if ((checkNum - (checkNum % 100000000000000)) / 100000000000000 >= 51
        && (checkNum - (checkNum % 100000000000000)) / 100000000000000 <= 55)
        {
            printf("MASTERCARD\n");
        }
        else if ((checkNum - (checkNum % 10000000000000)) / 10000000000000 == 37
        // i think the "e" below is a typo but i can't tell
        e|| (checkNum - (checkNum % 10000000000000)) / 10000000000000 == 34)
        {
            printf("AMEX\n");
        }
        else if ((checkNum - (checkNum % 1000000000000)) / 1000000000000 == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }


}

// a lot of languages also have auto format tools where you type a
// command and it format your code automatically. see if they have it 
// for C but i know they do have it for javascript and golang.

// also, you should enable autosave on vscode if you didn't already do that. it's annoying
// keep typing ctrl+s every few seconds

// i would strongly recommend using github for future assignments because it makes it
// easy to figure out what you changed between versions. also vscode works really well
// with github for seeing changes between commits

// otherwises good job with your first big project! almost a hundred lines!
