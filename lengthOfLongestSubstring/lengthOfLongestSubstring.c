int	lengthOfLongestSubstring(char *s)
{
	//letter_map, bu karakteri bu alt dizide görüp görmediğimizi takip etmek içindir
	int	letter_map[128] = {0};
	int	res;
	char	*start;
	char	*end;

	res = 0;
	start = s;
	end = s;
	while (*end)
	{
		// Zaten gördüğümüz bir harfe ulaştıysak - maksimum uzunluğu kontrol edin ve yeni bir alt dizi başlatın
		if (letter_map[*end])
		{
			res = (end - start > res) ? end - start : res;
			while (*start != *end)
			{
				letter_map[*start] = 0;
				start++;
			}
			start++;
			end++;
		}
		else
		{
			letter_map[*end] = 1;
			end++;
		}
	}
	return ((end - start) > res ? (end - start) : res);
}

#include <stdio.h>

int	main(void)
{
	int	res;
	char	*str;

	str = "abcabcbb";
	res = lengthOfLongestSubstring(str);
	printf("%d ", res);
}
