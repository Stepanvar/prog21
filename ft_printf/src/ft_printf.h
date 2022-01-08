#ifndef FT_PRINTF_H
#define FT_PRINTF_H
void	ft_p_field(void);
int	ft_length(char *str);
typedef	struct s_s{
	int	minus;
	int	plus;
	int	sharp;
	int	precision;
	int	space;
	int	zero;
	int	width;
	char	*arg;
}t_s;
int	ft_putstr(char *str);
void	ft_split(t_s s);
void	ft_field(char *str);
t_s	ft_handle_flag(t_s s);
t_s	ft_handle_width(t_s s);
void	ft_left_justif(t_s s, char *str);
void	ft_handling_justif(t_s s, char *str);
void	ft_right_justif(t_s s, char *str);
int	ft_print_num(int num);
long	ft_atoi(char *str);
void	ft_int_prints(int i);
t_s	ft_init_s(t_s s, char *arg1);

#endif
