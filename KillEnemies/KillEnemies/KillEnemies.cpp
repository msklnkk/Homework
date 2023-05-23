void KillEnemies(Context& ctx) {
	for (auto& subject : ctx.current_scene) {
		if (subject.enemy.enable) {
			for (auto& bullet : ctx.current_scene) {
				if (bullet.bullet.enabled) {

				}
			}
		}
	}
}