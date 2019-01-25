/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   div.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 18:25:03 by abaurens          #+#    #+#             */
/*   Updated: 2019/01/25 21:36:01 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bint/bint.h"

void		bidiv(t_bint *res, t_bint *mod, t_bint *n1, t_bint *n2)
{
	t_bint	r;
	t_bint	m;

	m = *n1;
	bi_set(&r, 0);
	if (bicmp(n1, n2) < 0)
	{
		*res = r;
		*mod = m;
		return ;
	}
	while (bicmp(&m, n2) >= 0)
	{
		bisub(&m, &m, n2);
		biincrement(&r);
	}
	*mod = m;
	*res = r;
}

unsigned int	bidiv_maxq9(t_bint *n1, t_bint *n2)
{
	unsigned int	r;
	t_bint			m;

	r = 0;
	m = *n1;
	if (bicmp(n1, n2) < 0)
	{
		*n1 = m;
		return (0);
	}
	while (bicmp(&m, n2) >= 0 && ++r)
		bisub(&m, &m, n2);
	*n1 = m;
	return (r);
}

/*
{x} note le plus grand entier inférieur ou égal à x (arrondir à l'inférieur || simple cast)

u = dividende (n1).
v = diviseur (n2).
q = res.

m + n = longueur du dividende (n1)
n = longueur du diviseur (n2)

m = longueur du dividende - longueur du diviseur

Multiplier u et v par d = {b/(v[n-1]+1]}
(c'est une étape de normalisation, l'important dans le choix
de d est que v[n-1] soit plus grand ou égal à B/2 à la fin)

Pour j de m à 0 par pas de -1
   qh = {(u[j+n]B + u[j+n-1])/v[n-1]}
   rh = (u[j+n]B+u[j+n-1]) mod v[n-1]
   Si qh = B ou qh*v[n-2] > rh*B + u[j+n-2]
      qh = qh-1
      rh = rh +v[n-1]
      si rh < B et qh*v[n-2] > rh*B + u[j+n-2]
         qh = qh -1
         rh = rh + v[n-1]
      fin si
   fin si
   u = u - qh v B^j
   si u < 0
      u = u + v
      qh = qh - 1
   fin si
   q[j] = qh
fin pour

exemple :
B = 10
u = 256
v = 127

v[n - 1] = le plus grand digit significatif de v
// Multiplier u et v par d = {b/(v[n-1]+1]}
d = {10 / (1 + 1)} = {10 / 2} = {5} = 5

u = u * d = 256 * 5 = 1280
v = v * d = 127 * 5 = 635

// Le but est que v[n-1] soit plus grand ou égal à B/2 à la fin
(v[n - 1] = 6) <= (10 / 2)
//cette etape est reussie


//	u = 01280
//	v = 0635
//	n = len(v) = 3
//	m + n = len(u) = 4
//	m = len(n1) - len(n2) = (len(u) - n) = ((m + n) - n) = (4 - 3) = 1

//	j = m = (len(u) - len(v)) = (4 - 3) = 1
//Pour j de m à 0 par pas de -1


j = 1
tant que j > 0
{

	j = 1
	//qh = {(u[j + n] * B + u[j + n - 1]) / v[n - 1]}
	//qh = {(u[1 + 3] * B + u[1 + 2]) / v[3 - 1]}
	//qh = {(u[4] * B + u[3]) / v[2]}
	//qh = {(0 * B + 1) / 6}
	//qh = {1 / 6}
	qh = 0

	//rh = (u[j + n] * B + u[j + n - 1]) % v[n - 1]
	//rh = (u[1 + 3] * B + u[1 + 3 - 1]) % v[3 - 1]
	//rh = (u[3] * B + u[3]) % v[2]
	//rh = (0 * B + 1) % 6
	rh = 1

	//Si qh = B ou qh * v[n - 2] > rh * B + u[j + n - 2]
	//if (qh == B || (qh * v[3 - 2] > rh * B + u[1 + 3 - 2]))
	//if (qh == B || (qh * v[1] > rh * B + u[2]))
	//if (qh == B || (qh * 3 > rh * B + 2))
	//if (0 == B || (0 * 3 > 1 * B + 2))
	//if (0 == 10 || (0 > (1 * 10 + 2)))
	if (0 == 10 || (0 > 12))
		//ON ENTRE PAS

	//u = u - qh * v * B^j
	//u = 1280 - 0 * 635 * B^1
	u = 1280

	//si u < 0
	//if (u < 0)
	if (1280 < 0)
		//ON ENTRE PAS

	//q[j] = qh
	q[1] = 0

	j--;

	j = 0
	//qh = {(u[j + n] * B + u[j + n - 1]) / v[n - 1]}
	//qh = {12 / 6}
	qh = 2

	//rh = (u[j + n] * B + u[j + n - 1]) % v[n - 1]
	//rh = 12 % 2
	rh = 0

	//if (qh = B || (qh * v[n - 2] > rh * B + u[j + n - 2]))
	//if (2 == 10 || (2 * 3 > 8))
	if (2 == 10 || 6 > 8)
		//ON ENTRE PAS

	//u = u - qh * v * B^j
	//u = 1280 - 2 * 635 * 10^0
	//u = 1280 - 1270
	u = 10

	//if (u < 0)
	if (10 < 0)
		//ON ENTRE PAS

	//q[j] = qh
	q[0] = 2
}

q = "02"


exemple 2:
u = 1234
v = 45

v[n - 1] = le plus grand digit significatif
// Multiplier u et v par d = {b/(v[n-1]+1]}
d = {10 / (4 + 1)} = {10 / 5} = {2} = 2

u = u * d = 1234 * 2 = 2468
v = v * d = 45 * 2 = 90

// Le but est que v[n-1] soit plus grand ou égal à B/2 à la fin
(v[n - 1] = 9) <= (10 / 2)
cette etape est reussie

*/

# define B (((unsigned long)MAX_BINT_VALS) + 1)

static void		normalize(t_bint *u, t_bint *v, const t_bint *n1, const t_bint *n2)
{
	unsigned long	d;
	size_t			n;

	d = B;
	n = n2->len;
	d /= ((t_proc)n2->blks[n - 1] + 1);
	bimulint(u, n1, d);
	bimulint(v, n2, d);
	BIASSERT(v->blks[v->len - 1] > (B / 2), "normalisation process failed");
}

void			bidiv_knuth(t_bint *res, const t_bint *n1, const t_bint *n2)
{
	t_bint		u;
	t_bint		v;
	size_t		j;
	t_proc		qh;
	t_proc		rh;

	normalize(&u, &v, n1, n2);
	j = n1->len - n2->len + 1;
	while (j-- > 0)
	{
		/* attention si [j + v.len (- 1)] > u.len */
		qh = (u.blks[j + v.len] * B + u.blks[j + v.len - 1]) / v.blks[v.len - 1];
		rh = (u.blks[j + v.len] * B + U.blks[j + v.len - 1]) % v.blks[v.len - 1];
		if (qh == B || (qh * v.blks[v.len - 2] > rh * B + u.blks[j + v.len - 2]))
		{
			qh--;
			rh += v.blks[v.len - 1];
			if (0/*COND*/)
			{
				qh--;
				rh += v.blks[v.len - 1];
			}
		}
	}
}

/*
Pour j de m à 0 par pas de -1
   qh = {(u[j+n]B + u[j+n-1])/v[n-1]}
   rh = (u[j+n]B+u[j+n-1]) mod v[n-1]
   Si qh = B ou qh*v[n-2] > rh*B + u[j+n-2]
      qh = qh - 1
      rh = rh + v[n-1]
      si rh < B et qh*v[n-2] > rh*B + u[j+n-2]
         qh = qh -1
         rh = rh + v[n-1]
      fin si
   fin si
   u = u - qh v B^j
   si u < 0
      u = u + v
      qh = qh - 1
   fin si
   q[j] = qh
fin pour
*/
unsigned int	bidiv10(t_bint *res, t_bint *n1)
{
	size_t		i;
	t_proc		c;
	t_bint		r;

	c = 0;
	r.len = 0;
	if (bicmplng(n1, 10) < 0 && ((c = n1->blks[0]) || 1))
	{
		bi_set(res, 0);
		return (c);
	}
	i = n1->len;
	while (i-- > 0)
	{
		c = ((c << BIT_PER_BLOCK) | n1->blks[i]);
		if ((r.blks[i] = (c / 10)) || r.len)
			r.len++;
		c %= 10;
	}
	if (r.len == 0)
		r.len = 1;
	*res = r;
	return (c);
}
