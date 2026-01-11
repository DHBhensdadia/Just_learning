#include <iostream>

using std::cout;
using std::cin;

class patterns
{
    private :
        static void print_p1 (void);
        static void print_p2 (void);
        static void print_p3 (void);
        static void print_p4 (void);
        static void print_p5 (void);
        static void print_p6 (void);
        static void print_p7 (void);
        static void print_p8 (void);
        static void print_p9 (void);
        static void print_p10 (void);
        static void print_p11 (void);
        static void print_p12 (void);
        static void print_p13 (void);
        static void print_p14 (void);
        static void print_p15 (void);
     
    public :
        static void (*print_pattern[])(void);
};

int main()
{
    bool flag;
    do 
    {
        flag = false;
        int n;
        cout << "Which patten you want to print out ? (enter 1 to 15) : ";
        cin >> n;

        if (n > 0 && n < 16)
        {
            patterns::print_pattern[n - 1]();
        }
        else 
        {
            cout << "Invalid input, try again !\n";
            flag = true;
        }

        if (!flag)
        {
            cout << "\nwanna try again ? (answer in 1 / 0) : ";
            cin >> flag;
        }

    }while (flag);
    
}


void (*patterns::print_pattern[])(void) = { patterns::print_p1,
                                            patterns::print_p2,
                                            patterns::print_p3,
                                            patterns::print_p4,
                                            patterns::print_p5,
                                            patterns::print_p6,
                                            patterns::print_p7,
                                            patterns::print_p8,
                                            patterns::print_p9,
                                            patterns::print_p10, 
                                            patterns::print_p11,
                                            patterns::print_p12,
                                            patterns::print_p13,
                                            patterns::print_p14,
                                            patterns::print_p15,
                                          };


void patterns::print_p1 (void)
{
    int m, n;
    cout << "Enter no of Rows : ";
    cin >> n;
    cout << "Enter no of Columns : ";
    cin >> m;

    cout << "Here is your required pattern no 1 : \n\n";

    for (int i = 0; i < n; i++)                                                                                   // ******
    {                                                                                                             // ******
        for (int j = 0; j < m; j++)                                                                               // ******
        {                                                                                                         // ******
            cout << '*';                                                                                          // ******
        }                                                                                                         // ******
        cout << '\n';                                                                                             // ******
    }                                                                                                             // ******
}

void patterns::print_p2 (void)
{
    int m;
    cout << "Enter no of Rows : ";
    cin >> m;

    cout << "Here is your required pattern no 2 : \n\n";

    for (int i = 1; i <= m; i++)                                                                                  // *
    {                                                                                                             // **
        for (int j = 0; j < i; j++)                                                                               // ***
        {                                                                                                         // ****
            cout << '*';                                                                                          // *****
        }                                                                                                         // ******
        cout << '\n';                                                                                             // *******
    }                                                                                                             // ********

}

void patterns::print_p3 (void)
{
    int m;
    cout << "Enter no of Rows : ";
    cin >> m;

    cout << "Here is your required pattern no 3 : \n\n";

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j << ' ';
        }
        cout << '\n';
    }

    // 1 
    // 1 2 
    // 1 2 3 
    // 1 2 3 4 
    // 1 2 3 4 5 
}

void patterns::print_p4 (void)
{
    int m;
    cout << "Enter no of Rows : ";
    cin >> m;

    cout << "Here is your required pattern no 4 : \n\n";

    for (int i = 1; i <= m; i++)
    {
        int n_col = m - i + 1;
        for (int j = n_col; j > 0; j--)
        {
            cout << n_col << ' ';
        }
        cout << '\n';
    }

    // 5 5 5 5 5 
    // 4 4 4 4 
    // 3 3 3 
    // 2 2 
    // 1 
}

void patterns::print_p5 (void)
{
    int m;
    cout << "Enter no of Rows : ";
    cin >> m;

    cout << "Here is your required pattern no 5 : \n\n";

    for (int i = 1; i <= m; i++)
    {
        int n_col = m - i + 1;
        for (int j = 1; j <= n_col; j++)
        {
            cout << j << ' ';
        }
        cout << '\n';
    }

    // 1 2 3 4 5 
    // 1 2 3 4 
    // 1 2 3 
    // 1 2 
    // 1 
}

void patterns::print_p6 (void)
{
    int m;
    cout << "Enter no of Rows(up to 26) : ";
    cin >> m;

    cout << "Here is your required pattern no 4 : \n\n";

    for (int i = 1; i <= m; i++)
    {
        int n_col = m - i + 1;
        for (int j = n_col; j > 0; j--)
        {
            cout << (char)('A' + n_col - 1) << ' ';
        }
        cout << '\n';
    }

    // E E E E E 
    // D D D D 
    // C C C 
    // B B 
    // A 
}

void patterns::print_p7 (void)
{
    int m;
    cout << "Enter no of Rows(up to 26) : ";
    cin >> m;

    cout << "Here is your required pattern no 7 : \n\n";

    for (int i = 1; i <= m; i++)
    {
        int n_col = m - i + 1;
        for (int j = 0; j < n_col; j++)
        {
            cout << (char)('A' + j) << ' ';
        }
        cout << '\n';
    }

    // A B C D E 
    // A B C D 
    // A B C 
    // A B 
    // A 
}

void patterns::print_p8 (void)
{
    int m;
    cout << "Enter no of Rows : ";
    cin >> m;

    cout << "Here is your required pattern no 8 : \n\n";

    int count{1};
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << count++ << ' ';
        }
        cout << '\n';
    }

    // 1 
    // 2 3 
    // 4 5 6 
    // 7 8 9 10 
    // 11 12 13 14 15 
}

void patterns::print_p9 (void)
{
    int m;
    cout << "Enter no of Rows : ";
    cin >> m;

    cout << "Here is your required pattern no 9 : \n\n";

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m + i; j++)
        {
            if ( j < m - i - 1)
            {
                cout << ' ';
            }
            else
            {
                cout << '*';
            }
        }
        cout << '\n';
    }

    //     *
    //    ***
    //   *****
    //  *******
    // *********

}

void patterns::print_p10 (void)
{
    
    int m;
    cout << "Enter no of Rows : ";
    cin >> m;

    cout << "Here is your required pattern no 10 : \n\n";

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < 2*m - i - 1; j++)
        {
            if ( j < i)
            {
                cout << ' ';
            }
            else
            {
                cout << '*';
            }
        }
        cout << '\n';
    }

    // *********
    //  *******
    //   *****
    //    ***
    //     *

}

void patterns::print_p11 (void)
{
    int m;
    cout << "Enter no of Rows : ";
    cin >> m;

    cout << "Here is your required pattern no 11 : \n\n";

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m + i; j++)
        {
            if ( j < m - i - 1)
            {
                cout << ' ';
            }
            else
            {
                cout << '*';
            }
        }
        cout << '\n';
    }

    for (int i = 1; i < m; i++)
    {
        for (int j = 0; j < 2*m - i - 1; j++)
        {
            if ( j < i)
            {
                cout << ' ';
            }
            else
            {
                cout << '*';
            }
        }
        cout << '\n';
    }

    //     *
    //    ***
    //   *****
    //  *******
    // *********
    //  *******
    //   *****
    //    ***
    //     *

}

void patterns::print_p12 (void)
{
    int m;
    cout << "Enter no of Rows : ";
    cin >> m;

    cout << "Here is your required pattern no 12 : \n\n";

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << j + 1 << ' ';
        }

        for (int j = 0; j < 2 * (m - i - 1); j++)
        {
            cout << "  ";
        }

        for (int j = i; j >= 0; j--)
        {
            cout << j + 1 << ' ';
        }

        cout << '\n';
    }

    // 1                 1 
    // 1 2             2 1 
    // 1 2 3         3 2 1 
    // 1 2 3 4     4 3 2 1 
    // 1 2 3 4 5 5 4 3 2 1 

}

void patterns::print_p13 (void)
{
    int m;
    cout << "Enter no of half Rows : ";
    cin >> m;
   
    cout << "Here is your required pattern no 13 : \n\n";

    for (int i = 0; i < m; i++)
    {
        for (int j = 1; j <= 2 * m; j++)
        {
            if (j > m - i && j <= m + i)
            {
                cout << ' ' << ' ';
            }
            else 
            {
                cout << '*' << ' ';
            }
        }

        cout << '\n';
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 1; j <= 2 * m; j++)
        {
            if (j <= i + 1 || j >= 2*m - i)
            {
                cout << '*' << ' ';
            }
            else 
            {
                cout << ' ' << ' ';
            }
        }

        cout << '\n';
    }

    // * * * * * * * * * * 
    // * * * *     * * * * 
    // * * *         * * * 
    // * *             * * 
    // *                 * 
    // *                 * 
    // * *             * * 
    // * * *         * * * 
    // * * * *     * * * * 
    // * * * * * * * * * * 
}

void patterns::print_p14 (void)
{
    int m;
    cout << "Enter no of Rows : ";
    cin >> m;

    cout << "Here is your required pattern no 14 : \n\n";
    for (int i = 0; i < (m * 2); i ++)
    {
        for (int j = 0; j < (m * 2); j++)
        {
            int x{i < m ? i : 2*m - i - 1};
            int y{j < m ? j : 2*m - j - 1};
            int min = (x) < (y) ? (x) : (y);

            cout << m - min << ' ';
        }

        cout << '\n';
    }

    // 5 5 5 5 5 5 5 5 5 5 
    // 5 4 4 4 4 4 4 4 4 5 
    // 5 4 3 3 3 3 3 3 4 5 
    // 5 4 3 2 2 2 2 3 4 5 
    // 5 4 3 2 1 1 2 3 4 5 
    // 5 4 3 2 1 1 2 3 4 5 
    // 5 4 3 2 2 2 2 3 4 5 
    // 5 4 3 3 3 3 3 3 4 5 
    // 5 4 4 4 4 4 4 4 4 5 
    // 5 5 5 5 5 5 5 5 5 5 

}

void patterns::print_p15 (void)
{
    int base, n, m;
    cout << "Enter no of elemets in Inner Triangle : ";
    cin >> base;
    cout << "Enter no of Inner Triangles in Enclosing Triangle : ";
    cin >> n;
    cout << "Enter no of Enclosing Triangles in Full Triangle : ";
    cin >> m;

    cout << "Here is your required pattern no 14 : \n\n";

    int i, j, k, l, h, h2, t, t2, b, b2;

    for (h2 = 1; h2 <= m; h2++)
    {
        for(h = 1; h <= n; h++)
        {
            for(i = 1; i <= base; i++)
            {
                for(t2 = (m-h2)*n; t2 > 0; t2--)
                {
                    for(b2 = 0; b2 < base; b2++)
                    {
                        cout << ' ';
                    }
                }
                for(t = (n-h); t > 0; t--)
                {
                    for(b = 0; b < base; b++)
                    {
                        cout << ' ';
                    }
                }
                for (l = 0; l < h2; l++)
                {
                    for (k = 0; k < h; k++)
                    {
                        for (j = 1; j < (2*base); j++)
                        {
                            if (i == base)
                            {
                                (j % 2 == 1) ? (cout << '*') : (cout << ' ');
                            }
                            else
                            {
                                if ((j == base - i + 1) || (j == base + i - 1))
                                    cout << '*';
                                else
                                    cout << ' ';
                            }
                        }
                        cout << ' ';
                    }
                    for(t = n - h; t > 0; t--)
                    {
                        for (b = 0; b < base; b++)
                        {
                            cout << "  ";
                        }
                    }
                }
                cout << '\n';
            }
        }
    }

    //                              *
    //                             * *                        
    //                            *   *                       
    //                           *     *                      
    //                          * * * * *                     
    //                         *         *               
    //                        * *       * *              
    //                       *   *     *   *             
    //                      *     *   *     *            
    //                     * * * * * * * * * *           
    //                    *         *         *     
    //                   * *       * *       * *    
    //                  *   *     *   *     *   *   
    //                 *     *   *     *   *     *  
    //                * * * * * * * * * * * * * * * 
    //               *                             *                         
    //              * *                           * *                        
    //             *   *                         *   *                       
    //            *     *                       *     *                      
    //           * * * * *                     * * * * *                     
    //          *         *                   *         *               
    //         * *       * *                 * *       * *              
    //        *   *     *   *               *   *     *   *             
    //       *     *   *     *             *     *   *     *            
    //      * * * * * * * * * *           * * * * * * * * * *           
    //     *         *         *         *         *         *     
    //    * *       * *       * *       * *       * *       * *    
    //   *   *     *   *     *   *     *   *     *   *     *   *   
    //  *     *   *     *   *     *   *     *   *     *   *     *  
    // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *     

}
