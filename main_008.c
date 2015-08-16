/* Copyright 2013 goodyoga all rights reserved. */

#include <stdint.h>   /* uint32_t */
#include <stdio.h>    /* printf   */
#include <stdlib.h>   /* atoi,exit   */
#include <string.h>   /* strlen   */
#include <unistd.h>   /* getopt   */

void usage(void);
char *prog;
unsigned long long int is_n_consecutive_digits(const char *p, unsigned long long int digits);

/**
 * @file
 * @addtogroup EULER_008  Euler_008_largest_product_in_a_series
 * @{
 */

/**
 * 
 * @param p
 * @param digits
 * @return
 */
unsigned long long int is_n_consecutive_digits(const char *p, unsigned long long int digits)
{
    uint32_t i;
    unsigned long long temp = 1;
    
    for  ( i = 0 ; *p && (i < digits ) ; i++)
    {
        if(p[i] != p[i+digits-1])
            return 0;
        else 
             temp *= (unsigned long long)(p[i] - '0');
    }
    return temp;
}

/**
 * @brief find 13 consecutive digits
 * 
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char **argv)
{
    unsigned long long int max = 0;
    unsigned long long int len_problem;
    unsigned long long int digits;
    unsigned long long int i;
    int opt;
    char *p;

    char *problem =
    "73167176531330624919225119674426574742355349194934"
    "96983520312774506326239578318016984801869478851843"
    "85861560789112949495459501737958331952853208805511"
    "12540698747158523863050715693290963295227443043557"
    "66896648950445244523161731856403098711121722383113"
    "62229893423380308135336276614282806444486645238749"
    "30358907296290491560440772390713810515859307960866"
    "70172427121883998797908792274921901699720888093776"
    "65727333001053367881220235421809751254540594752243"
    "52584907711670556013604839586446706324415722155397"
    "53697817977846174064955149290862569321978468622482"
    "83972241375657056057490261407972968652414535100474"
    "82166370484403199890008895243450658541227588666881"
    "16427171479924442928230863465674813919123162824586"
    "17866458359124566529476545682848912883142607690042"
    "24219022671055626321111109370544217506941658960408"
    "07198403850962455444362981230987879927244284909188"
    "84580156166097919133875499200524063689912560717606"
    "05886116467109405077541002256983155200055935729725"
    "71636269561882670428252483600823257530420752963450";
    prog = argv[0];
    digits = 13;
    len_problem = strlen(problem);
    
    while ( -1 != (opt = getopt(argc, argv, "ahdn:")) )
    {
        if('h' == opt)
        {
            usage();
            exit(EXIT_SUCCESS);
        }
        else if ('d' == opt)
        {
            digits = strtoul(optarg, &p, 0);
        }
        else if ('n' == opt)
        {
            max = strtoull(optarg, &p, 0);
        }
    }
    
    printf("finding %llu consecutive digits ...\n", digits);


    i = 0;
    while ( i < (len_problem - digits))
    {
        unsigned long long temp;
        temp = is_n_consecutive_digits(problem+i, digits);
        if (max < temp)
        {
            max = temp;
        }
        i++;
    }
    
    printf("answer: %llu th prime is %llu\n", i, max);
    return EXIT_SUCCESS;
}

/**
 * @}
 */

/**
 * show help 
 */
void usage(void)
{
    printf("    http://projecteuler.net/problem=8\n");
    printf("    [Problem 8] Largest product in a series\n");
    printf("    Find the greatest product of five consecutive digits in the 1000-digit number.\n"
           "    73167176531330624919225119674426574742355349194934\n"
           "    96983520312774506326239578318016984801869478851843\n"
           "    85861560789112949495459501737958331952853208805511\n"
           "    12540698747158523863050715693290963295227443043557\n"
           "    66896648950445244523161731856403098711121722383113\n"
           "    62229893423380308135336276614282806444486645238749\n"
           "    30358907296290491560440772390713810515859307960866\n"
           "    70172427121883998797908792274921901699720888093776\n"
           "    65727333001053367881220235421809751254540594752243\n"
           "    52584907711670556013604839586446706324415722155397\n"
           "    53697817977846174064955149290862569321978468622482\n"
           "    83972241375657056057490261407972968652414535100474\n"
           "    82166370484403199890008895243450658541227588666881\n"
           "    16427171479924442928230863465674813919123162824586\n"
           "    17866458359124566529476545682848912883142607690042\n"
           "    24219022671055626321111109370544217506941658960408\n"
           "    07198403850962455444362981230987879927244284909188\n"
           "    84580156166097919133875499200524063689912560717606\n"
           "    05886116467109405077541002256983155200055935729725\n"
           "    71636269561882670428252483600823257530420752963450\n\n");
    printf("    -h: show this help\n"
           "    -a: show additional messages\n"
           "    -n <number>: solve this with max <number>\n");
    return;
}


