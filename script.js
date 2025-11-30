document.addEventListener('DOMContentLoaded',()=>{
  // Theme toggle: persist choice and initialize from preference/localStorage
  const body = document.body;
  const toggle = document.getElementById('theme-toggle');

  function applyTheme(theme){
    body.setAttribute('data-theme', theme);
    if(toggle){
      toggle.textContent = theme === 'dark' ? '🌙' : '☀️';
      toggle.setAttribute('aria-pressed', theme === 'dark' ? 'true' : 'false');
    }
    try{ localStorage.setItem('theme', theme); }catch(e){}
  }

  const stored = (()=>{ try { return localStorage.getItem('theme') } catch(e){ return null } })();
  const prefersDark = window.matchMedia && window.matchMedia('(prefers-color-scheme: dark)').matches;
  // If user hasn't stored a preference, prefer a light (site) theme on the homepage
  if(!stored && document.body.classList.contains('home')){
    applyTheme('light');
  } else {
    applyTheme(stored || (prefersDark ? 'dark' : 'light'));
  }

  if(toggle){
    toggle.addEventListener('click', ()=>{
      const next = body.getAttribute('data-theme') === 'dark' ? 'light' : 'dark';
      applyTheme(next);
    });
  }

  // Simple click analytics for cards
  document.querySelectorAll('.card').forEach(card=>{
    card.addEventListener('click',()=>{
      const name = card.querySelector('h3')?.innerText || 'member';
      console.log('Card clicked:',name);
    });
  });
});
