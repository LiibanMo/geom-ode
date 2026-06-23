# geom-ode

Riemannian manifold-constrained Neural ODE solver built in C++

## Manifold Ordinary Equation

$$\dot{\mathbf{z}} = f(\mathbf{z}(t), t) \in T_{\mathbf{z}(t)}M, \quad \mathbf{z}(t_0) = \mathbf{z}_0$$

## Computation of the Manifold Continuous Normalizing Flow

The general equation of the log change-of-variables of a multivariate distribution $\mathbf{z} \sim \pi$ to $\mathbf{x} = g(\mathbf{z}) \sim p(\mathbf{x})$ is

$$
\begin{aligned}
\log p(\mathbf{x}) &= \log \left(\pi(g^{-1}(\mathbf{x})) \left|\det\frac{\partial g^{-1}}{\partial \mathbf{x}}\right|\right) \\
&= \log \pi(\mathbf{z}) + \log \left|\det\frac{\partial \mathbf{z}}{\partial \mathbf{x}}\right| \\
&= \log \pi(\mathbf{z}) - \log \left|\det\frac{\partial \mathbf{x}}{\partial \mathbf{z}}\right| \\
\end{aligned}
$$

where $f : \mathbf{z} \mapsto \mathbf{x}$ is a local diffeomorphism about $\mathbf{z}$.

Given a time step $t_n$:

$$t_{n+1} = t_n + \Delta t$$

therefore if the change-of-variables is applied to $\mathbf{x} = \mathbf{z}(t_{n+1}) = \mathbf{z}(t_n + \Delta t)$, we have

$$
\log p(\mathbf{z}(t_{n+1})) = \log \pi(\mathbf{z}(t)) - \log \left|\det\frac{\partial \mathbf{z}(t_{n+1})}{\partial \mathbf{z}(t_n)} \right|.
$$

By applying the Taylor expansion of $z(t + \Delta t)$ we get:

$$
\mathbf{z}(t + \Delta t) = \mathbf{z}(t) + \Delta t  f(\mathbf{z}(t), t) + O((\Delta t)^2).
$$

Therefore:

$$
\frac{\partial \mathbf{z}(t + \Delta t)}{\partial \mathbf{z}(t)} \approx I + \Delta t \frac{\partial f}{\partial \mathbf{z}}.
$$

TBC
