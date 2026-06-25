# geom-ode

Riemannian manifold-constrained Neural ODE solver built in C++

## The Setup

Suppose the sampled data $X = \lbrace x_i\rbrace_{i \in D}$ lives on a known Riemannian $n$-manifold $(\mathcal{M}, g)$, where $D$ is the cardinality of the dataset.

Is it possible for a model to learn the flow of data given a starting simple prior?

Let $z_i : [0, 1] \to \mathcal{M}$ be the curve modelling the trajectory of a point where $z_i(0)$ is sampled from a simple distribution and $z_i(1) = x_i$.

Define $Z = \lbrace z_i\rbrace_{i \in D}$ to be the collection of such curves.

## Manifold Ordinary Equation

### Setup

Let $\Delta t > 0$ be small and let $T = \lbrace t_j : j \in \{0, 1, \dots, N\}\rbrace$, where $N \in \mathbb{N}$, be a set of time-steps such that

$$
\begin{aligned}
0 = t_0 < t_1 < &\dots < t_{N-1} < t_{N} = 1 \\
t_{j+1} &= t_j + \Delta t, \quad j \in \{1, \dots, N-1\}.
\end{aligned}
$$

### Change of Variables: Manifold Volume Form

Let $a, b \in \mathcal{M}$. Now suppose $(U_a, \varphi_a)$ and $(U_b, \varphi_b)$ are coordinate charts for $a$ and $b$ respectively such that $h(U_a) \cap U_b \ne \emptyset$. Moreover, define a $h : M \to M$ such that $h(a) = b$ and $h$ is a local diffeomorphism about $a$.

Define $dV_g = \sqrt{\det g} \; dx_1 \wedge \dots \wedge dx_n : \mathcal{M} \to \Lambda^n T^*\mathcal{M}$ to be the volume form of $(\mathcal M, g)$ and define $p(x)$ to be the probability density function of an arbitrary variable $x$.

The change of variable formula via the manifold volume form applied to $h(a) = b$ is

$$
p(a) \; dV_g(a) = h^*(p(b) \; dV_g(b)),
$$

where $h^*: T^r_s\mathcal{M} \to T^r_s\mathcal{M}$ is the pullback along $h$.

By definition of the pullback, the formula evaluates to become:

$$
\begin{aligned}
p(a) \; dV_g(a) &= p(h(a)) \; (h^*dV_g)(a) \\
&= p(b) \; |\det D_a h| \; dV_g(a) \\
\implies p(a) &= p(b) |\det D_a h|
\end{aligned}
$$

By taking logs on both sides:

$$
\log p(a) = \log p(b) + \log |\det D_a h|
$$

Define $\hat{h} \equiv \varphi_b \circ h \circ \varphi^{-1}_a : \mathbb{R}^n \to \mathbb{R}^n$ to be the Euclidean representation of $h$.

Therefore:

$$
\begin{aligned}
\left|\det D_{\varphi_a(a)} \hat h\right| &= \left|\det D_{h(a)} \varphi_b \right| \left|\det D_a h\right| \left|\det D_a \varphi_a \right|^{-1} \\
\implies \log p(a) &= \log p(b) + \log \left|\det D_{\varphi_a(a)} \hat{h} \right| - \log \left|\det D_{h(a)} \varphi_b\right| + \log \left|\det D_a \varphi_a \right| \\
\end{aligned}
$$

### The Application

Let $z(t) \in Z$ be any curve. Given time $t_j \in T$, by setting $a = z(t_j)$, $b = z(t_{j+1})$ such that $\Delta t$ is small enough for both $z(t_j)$ and $z(t_{j+1})$ to have the same chart $(U, \varphi)$ (therefore $\varphi_a \equiv \varphi_b \equiv \varphi$), the change of variable via manifold volume form from $z(t_j)$ to $z(t_{j+1})$ becomes:

$$
\log p(z(t_{j+1})) =
$$

TBC
