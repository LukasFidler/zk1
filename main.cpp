#include <iostream>

constexpr int ASCII_CONS = 65;

enum reg_data
{
    SUM, COUNT
};

int main ()
{
    char leftBrace;
    char symbol;
    char region;
    int data[26][2];
    for ( int i = 0; i < 26; ++i )
    {
        for ( int j = 0; j < 2; ++j )
        {
            data[i][j] = 0;
        }

    }
    int input_wage;
    printf ( "Data:\n" );
    if ( scanf ( " %c", &leftBrace ) != 1 || leftBrace != '{' )
    {
        printf ( "Nespravny vstup.\n" );
        return 0;
    }
    while ( true )
    {
        if ( scanf ( " %d %c %c", &input_wage, &region, &symbol ) != 3 || input_wage < 0
             || region < 'A'
             || region > 'Z'
             || ( symbol != ',' && symbol != '}' ))
        {
            printf ( "Nespravny vstup.\n" );
            return 0;
        }

        data[region - ASCII_CONS][SUM] += input_wage;
        data[region - ASCII_CONS][COUNT]++;
        if ( symbol == '}' )
        {
            break;
        }

    }

    fflush ( stdin );
    printf ( "Agregace:\n" );
    size_t max_char = 82;
    char* buffer;
    size_t character_cnt = 0;
    int wage_sum = 0;
    int wage_cnt = 0;
    getline ( &buffer, &max_char, stdin );

    while (( character_cnt = static_cast<size_t>(getline ( &buffer, &max_char, stdin ))))
    {
        if ( character_cnt > max_char - 1 )
        {
            printf ( "Nespravny vstup.\n" );
            return 0;
        } else if ( character_cnt < 2 )
        {
            break;
        }

        for ( int i = 0; i < character_cnt - 1; ++i )
        {
            if (( buffer[i] >= 'A' && buffer[i] <= 'Z' ) || buffer[i] == ' ' )
            {
                if ( buffer[i] == ' ' ) continue;
                wage_sum += data[buffer[i] - ASCII_CONS][SUM];
                wage_cnt += data[buffer[i] - ASCII_CONS][COUNT];

            } else
            {
                printf ( "Nespravny vstup.\n" );
                return 0;
            }
        }
        printf ( "= %f\n", ( wage_sum / ( double ) wage_cnt ));
        wage_sum = 0;
        wage_cnt = 0;
    }
    return 0;
}