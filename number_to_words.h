/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_to_words.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kochniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 14:30:00 by kochniak          #+#    #+#             */
/*   Updated: 2025/07/13 15:03:33 by kochniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NUMBER_TO_WORDS_H
# define NUMBER_TO_WORDS_H

# define MAX_DICT_SIZE 1000
# define BUF_SIZE 10000

typedef struct s_dict_entry
{
	char	*key;
	char	*value;
}	t_dict_entry;

typedef struct s_process_data
{
	char			*nmb;
	int				size;
	int				start;
	t_dict_entry	*dict;
	int				dict_size;
}	t_process_data;

extern t_dict_entry	*g_dict;
extern int			g_dict_size;

int		ft_strlen(char *str);
char	*ft_strdup(char *src);
char	*ft_strtrim(char *str);
char	*ft_split_once(char *str, char sep);
int		correct_nmb(char *n);
void	ft_putstr(char *str);
int		ft_strcmp(char *s1, char *s2);

int		load_dict(t_dict_entry *dict, char *filename);
void	print_dict(t_dict_entry *dict, int size);
void	free_dict(t_dict_entry *dict, int size);
char	*find_in_dict(char *key);

void	build_power_key(char *key, int index);

void	process1(char fi, t_dict_entry *dict, int dict_size);
void	process2(char se, char fi, t_dict_entry *dict, int dict_size);
void	process3(char *chars, t_dict_entry *dict, int dict_size);
int		partial_present(char se, char fi, t_dict_entry *dict, int dict_size);
void	convert_number_to_words(char *nmb, t_dict_entry *dict, int dict_size);
void	present(char fi, int index, t_dict_entry *dict, int dict_size);

#endif
